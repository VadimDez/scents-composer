/**
 * Created by Vadym Yatsyuk on 08.09.17
 */


const Router = require('express').Router;

let router = new Router();
router.get('/', (req, res) => {
  res.status(200).json('ok').end();
});

module.exports = router;