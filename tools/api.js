// export merged raylib APIs

import r from '@raylib/api'

const raylibJson = { 'defines': [], 'structs': [], 'aliases': [], 'enums': [], 'callbacks': [], 'functions': []}

const libs = [
  'raylib',  'raymath'
]

for (const field of Object.keys(raylibJson)) {
  for (const lib of libs) {
    for (const item of r[lib][field]) {
      if (!raylibJson[field].find(i => i.name === item.name)) {
        raylibJson[field].push(item)
      }
    }
  }
}


export default raylibJson
