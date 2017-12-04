function static128
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.083969 1.288174 0.943973 1.256815 7.379672 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

