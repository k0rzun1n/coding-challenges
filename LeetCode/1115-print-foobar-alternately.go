//go:build ignore

package main

type FooBar struct {
	n    int
	sync chan bool
}

func NewFooBar(n int) *FooBar {
	nfb := FooBar{n: n}
	nfb.sync = make(chan bool, 1)
	return &nfb
}

func (fb *FooBar) Foo(printFoo func()) {
	for i := 0; i < fb.n; i++ {
		// printFoo() outputs "foo". Do not change or remove this line.
		printFoo()
		fb.sync <- true
		<-fb.sync
	}
}

func (fb *FooBar) Bar(printBar func()) {
	for i := 0; i < fb.n; i++ {
		// printBar() outputs "bar". Do not change or remove this line.
		<-fb.sync
		printBar()
		fb.sync <- true
	}
}
