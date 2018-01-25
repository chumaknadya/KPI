import axios from 'axios'
import storage from "./storage/storage";
export default () => {
  return axios.create({
    baseURL: `http://localhost:8081/`,
    auth: {
      username: storage.state.username,
      password: storage.state.password,
    }
  })
}
