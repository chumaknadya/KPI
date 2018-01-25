import Vue from 'vue'
import Router from 'vue-router'
// import HelloWorld from '@/components/HelloWorld'
import AnimalsList from '@/components/AnimalsList.vue'
Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/api/v1/animals',
      name: 'AnimalsList',
      component: AnimalsList
    }
  ]
})
