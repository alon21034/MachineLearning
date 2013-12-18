x = [1 0;0 1;0 -1;-1 0;0 2;0 -2;-2 0];
y = [-1;-1;-1;1;1;1;1];

z(:,1) = x(:,2).^2 - 2*x(:,1) - 2;
z(:,2) = x(:,1).^2 - 2*x(:,2) + 3;

K = (y * y') .* (2 + x * x').^2;

opts = optimset('Algorithm','interior-point-convex');

alpha = quadprog(K, -ones(7,1), -eye(7,7), zeros(7, 1), y', 0, [], [], [], opts);
alpha


