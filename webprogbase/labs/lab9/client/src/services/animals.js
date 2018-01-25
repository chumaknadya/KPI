import API from './Api'
export default {
  find (arg) {
    console.log("filterString "+ arg)
    let query;
    if(arg)  query = `api/v1/animals?breed=${arg}`
    else  query = 'api/v1/animals?breed='
    return API().get(query)
  },
  getPages() {
    let query = `api/v1/amount`
    return API().get(query)
  },
  addAnimal(args) {
    console.log(args)
    let form = new FormData();
    for(var key in args){
      console.log(key,args[key])
      form.append(key,args[key]);
    }
    return API().post(`api/v1/animals/create`,form,{ headers: { 'Content-Type': 'multipart/form-data' }});
  },
  removeAnimal(id) {
     return API().post(`api/v1/animals/${id}`)
  },
  getPaginated(filter,page) {
    let query;
    if(page)  query = `api/v1/animals?page=${page}`
    else  query = 'api/v1/animals?breed='
    return API().get(query)
  }
}
