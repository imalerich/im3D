function method2
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 4.740964 3.488757 3.400138 3.860629 4.782828 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/war.obj 3840x2160');
t1 = [ 2.877987 1.884806 1.641471 1.717772 2.133848 ];
plot(x, t1, 'LineWidth', 3, 'DisplayName', 'models/dragon.obj 3840x2160');
t2 = [ 5.515146 3.504730 3.402892 3.451998 3.730830 ];
plot(x, t2, 'LineWidth', 3, 'DisplayName', 'models/blackdragon.obj 3840x2160');
t3 = [ 6.164862 3.697491 3.107172 3.507663 4.476351 ];
plot(x, t3, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

