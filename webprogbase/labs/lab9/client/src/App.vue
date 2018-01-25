<template>
  <div id="app">
    <animals-list/>
    <router-view/>
  </div>
</template>

<script>
import AnimalsList from '@/components/AnimalsList.vue'
import PageHeader from '@/components/PageHeader.vue'
import CreateAnimal from '@/components/CreateAnimal.vue'
export default {
  name: 'app',
  components: {
      AnimalsList,
      PageHeader,
      CreateAnimal
  }
}
</script>

<style>
#app {
  
}
</style>
