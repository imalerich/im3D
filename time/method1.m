function method1
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 4.741661 3.611441 3.266975 3.814722 4.591568 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/war.obj 3840x2160');
t1 = [ 2.887145 1.869071 1.640317 1.736492 2.114854 ];
plot(x, t1, 'LineWidth', 3, 'DisplayName', 'models/dragon.obj 3840x2160');
t2 = [ 5.495701 3.494502 3.376487 3.410626 3.754819 ];
plot(x, t2, 'LineWidth', 3, 'DisplayName', 'models/blackdragon.obj 3840x2160');
t3 = [ 6.188218 3.666473 3.143014 3.566216 4.543530 ];
plot(x, t3, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

