load hw5_14_train.dat

X = hw5_14_train(:,1:size(hw5_14_train,2)-1);
Y = hw5_14_train(:,size(hw5_14_train,2));

disp start

for sigma = [0.125 0.5 2]
    for C = [0.001 1 1000]

        sigma
        C
        model = svmtrain(Y, X, sprintf('-g %f -c %f -q', 0.5/sigma^2, C));
        svmpredict(Y, X, model);
        svmtrain(Y, X, sprintf('-g %f -c %f -v 5 -q', 0.5/sigma^2, C));
        model.totalSV
    end
end
