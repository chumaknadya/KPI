
let model = {
    tests: [],
    filterString: "",
    page : 1,
    pageCount: 1,
    range: 3,
    currentPage: 1
};
function getPageCount(){
    let xhttp = new XMLHttpRequest();
    xhttp.open("GET", `/api/v1/amount?name=${model.filterString}`, true);
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            let count = this.response;
            model.pageCount =  Math.ceil(count /3)
            console.log("page Count"+ model.pageCount)
        }
    }
    xhttp.send();
   
}
window.addEventListener('load', function () {
    getTests();
    console.log("ldldl")
    let inputEl = document.getElementById('filter_string');
    inputEl.addEventListener('input', function (e) {
        model.filterString = e.target.value;
        console.log(e.target.value)
        getTests()
    });
   inputEl.value = model.filterString;
   
});
async function getTests() {
    let xhttp = new XMLHttpRequest();
    this.tests = [];
    // задати опції запиту до веб-сервера (GET /get_data)
    xhttp.open("GET", `/api/v1/tests?name=${model.filterString}&page=${model.page}`, true);
    getPageCount()
    console.log(`/api/v1/tests?name=${model.filterString}&page=${model.page}`)  
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            let testsObj = JSON.parse(this.response);   
            let parsedTests = testsObj.slice((model.page-1)*3, model.page*3)
            model.tests = parsedTests;  
            //model.tests = testsObj;
            renderRequest();
        } 
      };
      // відправити запит
      xhttp.send();
}
function renderRequest() {
    document.getElementById('forEmptyItem').innerHTML = "";
    console.log(model.tests)
    if(model.tests.length != 0) {
        document.getElementById('items').innerHTML=
            renderTemplate('tests-list', {
                tests: model.tests,
                filterString: model.filterString
            }); 
        addPagination(); 
    } else{

        document.getElementById('items').innerHTML =""
        document.getElementById('forEmptyItem').innerHTML = "There are no tests";
        addPagination(); 
    }
    
 }
 function renderTemplate(id, args) {
    const template = document.getElementById('template-' + id).innerHTML;
    if (template) {
        console.log("Download template");
        return Mustache.render(template, args)
    }
}
function addPagination() {
            console.log("Tests length " + model.tests.length)
            let pagination = document.getElementById('myPagination')
            if(model.tests.length != 0) {
                console.log(model.pageCount)
                let pagination = document.getElementById('myPagination')
                    // clear container
                while (pagination.hasChildNodes()) {
                    pagination.removeChild(pagination.lastChild);
                }

                // pagination
                let paginationEl = document.createElement('div')
                paginationEl.className = 'pagination';

                // first page
                let firstEl = document.createElement('li')
                firstEl.className = 'page-item';
                let linkEl = document.createElement('a')
                linkEl.className = 'page-link';
                let linkText = document.createTextNode(String('<<'));
                linkEl.appendChild(linkText);
                if (model.page == 1) {
                    firstEl.className += ' disabled';
                } else {
                    linkEl.addEventListener('click', (event) => {
                        console.log(" go to first page.Current page was " + model.page)
                        model.page = 1;
                        getTests()
                    });
                }
                firstEl.appendChild(linkEl);
                paginationEl.appendChild(firstEl);

                //prev page
                let prevEl = document.createElement('li')
                prevEl.className = 'page-item';
                linkEl = document.createElement('a')
                linkEl.className = 'page-link';
                linkText = document.createTextNode(String('<'));
                linkEl.appendChild(linkText);
                if (model.page == 1) {
                    prevEl.className += ' disabled';
                } else {
                    linkEl.addEventListener('click', (event) => {
                        console.log(" go to prev page.Current page was " + model.page)
                        model.page = model.page -1
                        getTests()
                    });
                }
                prevEl.appendChild(linkEl);
                paginationEl.appendChild(prevEl);

                // page
                for (let i = Math.max(1, Number(model.page - model.range));
                    i <= Number(model.page) + Number(model.range) && i <= model.pageCount;
                    i++) {
                    let pageEl = document.createElement('li')
                    pageEl.className = 'page-item';

                    let linkEl = document.createElement('a')
                    linkEl.className = 'page-link';
                    let linkText = document.createTextNode(String(i));
                    linkEl.appendChild(linkText);
                    if (model.page == i) {
                        pageEl.className += ' active';
                    } else {
                        linkEl.addEventListener('click', (event) => {
                            model.page = i;
                            getTests()
                        });
                    }

                    pageEl.appendChild(linkEl);
                    paginationEl.appendChild(pageEl);
                }

                // next page
                let nextEl = document.createElement('li')
                nextEl.className = 'page-item';

                linkEl = document.createElement('a')
                linkEl.className = 'page-link';
                linkText = document.createTextNode(String(">"));
                linkEl.appendChild(linkText);
                if (model.page == model.pageCount) {
                    nextEl.className += ' disabled';
                } else {
                    linkEl.addEventListener('click', (event) => {
                        console.log(" go to next page .Current page was :" + model.page)
                        model.page = model.page + 1;
                        getTests()
                    });
                }

                nextEl.appendChild(linkEl);
                paginationEl.appendChild(nextEl);

                // last page
                let lastEl = document.createElement('li')
                lastEl.className = 'page-item';

                linkEl = document.createElement('a')
                linkEl.className = 'page-link';
                linkText = document.createTextNode(String(">>"));
                linkEl.appendChild(linkText);
                if (model.page == model.pageCount) {
                    lastEl.className += ' disabled';
                } else {
                    linkEl.addEventListener('click', (event) => {
                        console.log(" go to last page. Current page was : " + model.page)
                        model.page = model.pageCount
                        getTests()
                    });
                }

                lastEl.appendChild(linkEl);
                paginationEl.appendChild(lastEl);

                pagination.appendChild(paginationEl);
            } else {
                while (pagination.hasChildNodes()) {
                    pagination.removeChild(pagination.lastChild);
                }
            }
    }