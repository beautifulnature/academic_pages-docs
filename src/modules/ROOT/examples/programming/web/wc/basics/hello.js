class HelloWorld extends HTMLElement {
    constructor() {
        // very important
        // needed in every constructor
        // which extends another class
        super();

        // do magic here
        this.innerText = 'Hello World!';
    }
}

// tag::register[]
customElements.define('hello-world', HelloWorld);
// end::register[]