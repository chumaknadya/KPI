import Api from '@/services/Api'

export default {
  register (credentials) {
    console.log("register")
    return Api().post(`api/v1/register`, credentials)
  },
  login (credentials) {
    console.log("login")
    return Api().post(`api/v1/login`, credentials)
  }
}
