//go:build ignore

package main

type FooBar struct {
	n    int
	ping chan bool
	pong chan bool
}

func NewFooBar(n int) *FooBar {
	nfb := FooBar{n: n}
	nfb.ping = make(chan bool, 1)
	nfb.pong = make(chan bool, 1)
	nfb.ping <- true
	return &nfb
}

func (fb *FooBar) Foo(printFoo func()) {
	for i := 0; i < fb.n; i++ {
		<-fb.ping
		// printFoo() outputs "foo". Do not change or remove this line.
		printFoo()
		fb.pong <- true
	}
}

func (fb *FooBar) Bar(printBar func()) {
	for i := 0; i < fb.n; i++ {
		<-fb.pong
		// printBar() outputs "bar". Do not change or remove this line.
		printBar()
		fb.ping <- true
	}
}
