disp problem13

load hw5_13_train.dat;
load hw5_13_test.dat;
test_data = hw5_13_test;

for iter = 1:100

    n = mod(fix(rand * 100), 16)+1;
    m = mod(fix(rand * 100), 4)+17;

    t = hw5_13_train(n,:);
    hw5_13_train(n,:) = hw5_13_train(m, :);
    hw5_13_train(m,:) = t;

    data = hw5_13_train(1: fix(0.8*size(hw5_13_train, 1)) , 1:size(hw5_13_train,2));

    data_num = size(data, 1);
    dim = size(data, 2) - 1;

    X = data(:,1:dim);
    Y = data(:,dim+1);

    A = eye(dim+1, dim+1);
    A(1,1) = 0;

    c = zeros(dim+1, 1);

    p = [ones(data_num,1) X];

    for i = 1:data_num
       p(i,:) = Y(i) * p(i,:);
    end

    r(1:data_num) = -1;
    W = quadprog(A, c, -p, r);

    XX = hw5_13_test(:,1:dim);
    YY = hw5_13_test(:,dim+1);
    for i = 1:size(XX,1)
       res(i) = sign([1 XX(i,:)] * W);
    end

    for i = 1:size(X,1)
       margin(i) = abs([1 X(i,:)] * W) / norm(W);
    end
    out(iter, 1) = min(margin);
    out(iter, 2) = (1000 - sum(res .* transpose(YY)))/2000;

 end

 scatter(out(:,2), out(:,1))
