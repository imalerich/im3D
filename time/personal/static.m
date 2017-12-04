function static
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.077153 1.262176 0.823633 0.888333 7.151487 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

