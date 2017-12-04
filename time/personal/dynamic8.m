function dynamic8
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.253108 1.389646 0.881040 0.843262 7.132603 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

