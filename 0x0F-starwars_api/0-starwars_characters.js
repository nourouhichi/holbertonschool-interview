#!/usr/bin/node
const request = require('request');
const Id = process.argv[2];
const ApiUrl = 'https://swapi-api.hbtn.io/api/films/' + Id + '/';
request(ApiUrl, function (error, response, body) {
  if (error) console.error('error:', error);
  for (let i = 0; i < JSON.parse(body).characters.length; i++) {
    request(JSON.parse(body).characters[i], function (er, resp, bod) {
      console.log(JSON.parse(bod).name);
    });
  }
});
