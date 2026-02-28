require("dotenv").config();
const express = require("express");
const axios = require("axios");
const cors = require("cors");

const app = express();
app.use(cors());
app.use(express.json());

app.post("/push-to-github", async (req, res) => {
  try {
    const { filename, content } = req.body;

    const response = await axios.put(
      `https://api.github.com/repos/${process.env.GITHUB_USERNAME}/${process.env.REPO_NAME}/contents/${filename}`,
      {
        message: "Added LeetCode solution",
        content: Buffer.from(content).toString("base64")
      },
      {
        headers: {
          Authorization: `Bearer ${process.env.GITHUB_TOKEN}`,
          Accept: "application/vnd.github+json"
        }
      }
    );

    res.json({ success: true, data: response.data });
  } catch (err) {
    console.error(err.response?.data || err.message);
    res.status(500).json({ success: false, error: err.message });
  }
});

app.listen(5000, () => {
  console.log("Server running on 5000");
});