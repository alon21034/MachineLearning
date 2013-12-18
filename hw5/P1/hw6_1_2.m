clear

x = [1 0; 0 1; 0 -1; -1 0; 0 2; 0 -2; -2 0];

y = [-1 -1 -1 1 1 1 1]';

K = (y * y') .* (3 + x * x').^2;

alpha = quadprog(K, -ones(7, 1), [], [], y', 0, zeros(7, 1), [], [], optimset('LargeScale', 'off'));

[m n] = max(abs(alpha));
b = y(n) - (y.*alpha)' * (3 + x * x(n, :)').^2;


figure(3), clf
hold on
plot(x(y>0, 1), x(y>0, 2), 'o', 'MarkerSize', 10);
plot(x(y<0, 1), x(y<0, 2), 'x', 'MarkerSize', 10);

aa = alpha(4);
bb = 2/3;
cc = 9 * alpha(4) - b;
theta = 0:0.01:2*pi;

plot(3 + sqrt((cc)/aa)*cos(theta), sqrt((cc)/bb)*sin(theta), '--');
plot(x(2:6, 1), x(2:6, 2), 's', 'Markersize', 30);
plot(3 + sqrt((cc-1)/aa)*cos(theta), sqrt((cc-1)/bb)*sin(theta), '-');
plot(3 + sqrt((cc+1)/aa)*cos(theta), sqrt((cc+1)/bb)*sin(theta), '-');
xlabel('x[1]')
ylabel('x[2]')
h = legend('y = +1', 'y = -1', 'the hyperplane in the Z-space', 'on-the-boundary vectors', 'the fat boundary', 'Location', 'SouthWest');
set(h, 'Fontsize', 20);

axis([-3 8 -4 4])
hold off