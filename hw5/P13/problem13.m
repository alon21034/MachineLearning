disp problem13

load hw5_13_train.dat;
data = hw5_13_train;

data_num = size(data, 1);
dim = size(data, 2) - 1;

X = data(:,1:dim);
Y = data(:,dim+1);

A = zeros(dim+1, dim+1);

c = zeros(dim+1, 1);

p(1:data_num,) = y .* [1 X(1:data_num)];

