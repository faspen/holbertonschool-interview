#!/usr/bin/node
/* Print star wars characters */
const args = process.argv.slice(2);
if (args < 1) {
  console.log('Error');
  process.exit(1);
}
