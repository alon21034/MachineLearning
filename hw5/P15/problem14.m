load hw5_14_train.dat

X = hw5_14_train(:,1:size(hw5_14_train,2)-1);
Y = hw5_14_train(:,size(hw5_14_train,2));

disp start

for sigma = [0.125 0.5 2]
    for C = [0.001 1 1000]

        [sigma C]
        model = svmtrain(Y, X, sprintf('-g %f -c %f -q', 0.5/sigma^2, C));
        svmpredict(Y, X, model);
        model.totalSV/500
    end
end

for sigma = [0.125 0.5 2]
    for C = [0.001 1 1000]

        [sigma C]
        svmtrain(Y, X, sprintf('-g %f -c %f -v 5 -q', 0.5/sigma^2, C));
    end
end

disp =================p15=======================
for sigma = [0.125 0.5 2]
    for C = [0.001 1 1000]

        [sigma C]
        model = svmtrain(Y, X, sprintf('-s 3 -g %f -c %f -q', 0.5/sigma^2, C));
        predict = sign(svmpredict(Y, X, model));
        err = (500- sum(Y.*predict))/1000
        model.totalSV/500
    end
end

load hw5_14_train_1.dat
load hw5_14_train_2.dat
load hw5_14_train_3.dat
load hw5_14_train_4.dat
load hw5_14_train_5.dat

load hw5_14_test_1.dat
load hw5_14_test_2.dat
load hw5_14_test_3.dat
load hw5_14_test_4.dat
load hw5_14_test_5.dat

for sigma = [0.125 0.5 2]
    for C = [0.001 1 1000]


        X1 = hw5_14_train_1(:,1:size(hw5_14_train_1,2)-1);
        Y1 = hw5_14_train_1(:,size(hw5_14_train_1,2));
        
        X2 = hw5_14_train_2(:,1:size(hw5_14_train_2,2)-1);
        Y2 = hw5_14_train_2(:,size(hw5_14_train_2,2));
        
        X3 = hw5_14_train_3(:,1:size(hw5_14_train_3,2)-1);
        Y3 = hw5_14_train_3(:,size(hw5_14_train_3,2));
        
        X4 = hw5_14_train_4(:,1:size(hw5_14_train_4,2)-1);
        Y4 = hw5_14_train_4(:,size(hw5_14_train_4,2));
        
        X5 = hw5_14_train_5(:,1:size(hw5_14_train_5,2)-1);
        Y5 = hw5_14_train_5(:,size(hw5_14_train_5,2));
        [sigma C]
        
        XX1 = hw5_14_test_1(:,1:size(hw5_14_test_1,2)-1);
        YY1 = hw5_14_test_1(:,size(hw5_14_test_1,2));

        XX2 = hw5_14_test_2(:,1:size(hw5_14_test_2,2)-1);
        YY2 = hw5_14_test_2(:,size(hw5_14_test_2,2));
        
        XX3 = hw5_14_test_3(:,1:size(hw5_14_test_3,2)-1);
        YY3 = hw5_14_test_3(:,size(hw5_14_test_3,2));
        
        XX4 = hw5_14_test_4(:,1:size(hw5_14_test_4,2)-1);
        YY4 = hw5_14_test_4(:,size(hw5_14_test_4,2));
        
        XX5 = hw5_14_test_5(:,1:size(hw5_14_test_5,2)-1);
        YY5 = hw5_14_test_5(:,size(hw5_14_test_5,2));
        
        model1 = svmtrain(Y1, X1, sprintf('-s 3 -g %f -c %f -q', 0.5/sigma^2, C));
        predict1 = sign(svmpredict(YY1, XX1, model1));
        err1 = (100- sum(YY1.*predict1))/200;
        
        model2 = svmtrain(Y2, X2, sprintf('-s 3 -g %f -c %f -q', 0.5/sigma^2, C));
        predict2 = sign(svmpredict(YY2, XX2, model2));
        err2 = (100- sum(YY2.*predict2))/200;
        
        model3 = svmtrain(Y3, X3, sprintf('-s 3 -g %f -c %f -q', 0.5/sigma^2, C));
        predict3 = sign(svmpredict(YY3, XX3, model3));
        err3 = (100- sum(YY3.*predict3))/200;
        
        model4 = svmtrain(Y4, X4, sprintf('-s 3 -g %f -c %f -q', 0.5/sigma^2, C));
        predict4 = sign(svmpredict(YY4, XX4, model4));
        err4 = (100- sum(YY4.*predict4))/200;
        
        model5 = svmtrain(Y5, X5, sprintf('-s 3 -g %f -c %f -q', 0.5/sigma^2, C));
        predict5 = sign(svmpredict(YY5, XX5, model5));
        err5 = (100- sum(YY5.*predict5))/200;

        (err1+err2+err3+err4+err5)/5
    end
end




