let App = {
    setState: function (credentials) {
        if (credentials.login && credentials.password) {
            localStorage.setItem('login', credentials.login);
            localStorage.setItem('password', credentials.password);
            localStorage.setItem('isLogged', true);
        } else {
            localStorage.setItem('login', '');
            localStorage.setItem('password', '');
            localStorage.setItem('isLogged', false);
        }
    },
    getState: function () {
        return {
            login: localStorage.getItem('login'),
            password: localStorage.getItem('password'),
        }
    },
    isLogged: () => {
        return localStorage.getItem('isLogged') == true;
    },
    login: function () {
        console.log('try to login')
        const login = document.getElementById('login-username').value;
        console.log(document.getElementById('login-username').value)
        const password = document.getElementById('login-password').value;
        console.log(document.getElementById('login-password').value)
        let ajax = new XMLHttpRequest();
        ajax.open('POST', `/api/v1/login`);
        ajax.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
        ajax.onreadystatechange = function () {
            if (ajax.readyState === 4 && ajax.status === 200) {
                try {
                    const response = JSON.parse(ajax.responseText);
                    if (response.user_id) {
                        alert("login"+login+" password "+password)
                        App.setState({login: login, password: password})
                        window.location.href="/"
                        console.log('success')
                    } else {
                        console.log('unsuccess')
                    }
                } catch (e) {
                    console.log(e)
                }
            }

        };

        ajax.send(JSON.stringify({username: login, password: password}));
    }
};
