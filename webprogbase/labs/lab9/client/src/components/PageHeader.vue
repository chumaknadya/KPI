<template>
   <nav class="navbar navbar-inverse">
      <div class="container-fluid">
      <div class="navbar-header">
            <a class="navbar-brand" >N.Ch</a>
      </div>
      <ul class="nav navbar-nav">
                  <form class="navbar-form navbar-left" enctype="multipart/form-data">
                        <div class="input-group">
                              <input v-model="filterString" @input="searchReq"
                              type="text" class="form-control" name="breed" id="filter_string"  placeholder="Search">
                              <div class="input-group-btn">
                                    <i class="glyphicon glyphicon-search"></i>
                                    </button>
                              </div>
                        </div>
                  </form>
      </ul>  
      <ul class="nav navbar-nav navbar-right"> 
            <li><a ><span class="glyphicon glyphicon-user"></span> Sign Up</a></li>
            <li><a ><span class="glyphicon glyphicon-log-in"></span> Login</a></li>
      </ul>
      </div>
  </nav>
</template>
<script>


export default {
   name: 'Navbar',
      data () {
            return {
                  filterString:''
            }
      },
      watch: {

      },
      methods: {
            searchReq(event) {
                  console.log(event.target.value)
                  this.filterString = event.target.value;
                  this.$emit('newSearchreq', this.filterString);
            }
      }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
 
</style>
