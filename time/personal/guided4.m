function guided4
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.080330 1.285662 0.838019 0.898884 6.761821 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

