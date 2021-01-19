filename = 'salida.txt';
T = readtable(filename);

name = table2array(T(:,1:1));
n_coo = table2array(T(:,2:2));
t_coo = table2array(T(:,3:3));
n_coomkl = table2array(T(:,4:4));
t_coomkl = table2array(T(:,5:5));
n_csr = table2array(T(:,6:6));
t_csr = table2array(T(:,7:7));
n_csromp = table2array(T(:,8:8));
t_csromp = table2array(T(:,9:9));
n_csrmkl = table2array(T(:,10:10));
t_csrmkl = table2array(T(:,11:11));

x=categorical(name);

%--------------------------------------------------------------------------
% Create output figure file
%--------------------------------------------------------------------------
h = figure('Visible','off');
scatter(x,n_coo,'o');
hold on;
scatter(x,n_coomkl,'+');
hold on;
scatter(x,n_csr,'*');
hold on;
scatter(x,n_csromp,'.');
hold on;
scatter(x,n_csrmkl,'x');
hold on;
titleName = ['Normalized Time by Matrix'] ;
title(titleName)
xLabelName = [ 'Matrix Type' ] ;
xlabel(xLabelName)
ylabel('Normalized Time (s)')
legend('COO','COO-MKL','CSR','CSR-OMP','CSR-MKL')
print(h,'-dpng','figura.png');
close(h);

%--------------------------------------------------------------------------
% Create output figure file
%--------------------------------------------------------------------------
h = figure('Visible','off');
scatter(x,t_coo,'o');
hold on;
scatter(x,t_coomkl,'+');
hold on;
scatter(x,t_csr,'*');
hold on;
scatter(x,t_csromp,'.');
hold on;
scatter(x,t_csrmkl,'x');
hold on;
titleName = ['Total Time by Matrix'] ;
title(titleName)
xLabelName = [ 'Matrix Type' ] ;
xlabel(xLabelName)
ylabel('Total Time (s)')
legend('COO','COO-MKL','CSR','CSR-OMP','CSR-MKL')
print(h,'-dpng','figura1.png');
close(h);

%--------------------------------------------------------------------------
% Create output figure file
%--------------------------------------------------------------------------
h = figure('Visible','off');
scatter(x,t_coo,'o');
hold on;
scatter(x,t_csr,'*');
hold on;
titleName = ['Total Time by Matrix'] ;
title(titleName)
xLabelName = [ 'Matrix Type' ] ;
xlabel(xLabelName)
ylabel('Total Time (s)')
legend('COO','CSR')
print(h,'-dpng','figura2.png');
close(h);

%--------------------------------------------------------------------------
% Create output figure file
%--------------------------------------------------------------------------
h = figure('Visible','off');
scatter(x,n_coo,'o');
hold on;
scatter(x,n_csr,'*');
hold on;
titleName = ['Normalized Time by Matrix'] ;
title(titleName)
xLabelName = [ 'Matrix Type' ] ;
xlabel(xLabelName)
ylabel('Normalized Time (s)')
legend('COO','CSR')
print(h,'-dpng','figura3.png');
close(h);