import torch

# a = torch.tensor([2., 3.], requires_grad=True)
# b = torch.tensor([6., 4.], requires_grad=True)

a = torch.tensor([-1.], requires_grad=True)
b = torch.tensor([1.], requires_grad=True)

# opt = torch.optim.SGD((a,b), lr=0.0001)
opt = torch.optim.SGD((a,b), lr=0.1)

Q = 3*(a-3)**2 + b**2
# Q = 3*a**3 - b**2

Q.backward()
# Q.sum().backward()
# external_grad = torch.tensor([1., 1.])
# Q.backward(gradient=external_grad)

opt.step()

for _ in range(999):
    Q = 3*(a-3)**2 + b**2
    opt.zero_grad()
    Q.backward()
    opt.step()

# check if collected gradients are correct
print(9*a**2 == a.grad)
print(-2*b == b.grad)

cc-a
cc-a.grad
cc-b
cc-b.grad

#ctrl d?