function dynamic1
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 3.287317 2.210785 1.770884 4.542323 10.010094 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

