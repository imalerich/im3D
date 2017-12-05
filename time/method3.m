function method3
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 4.581305 2.797147 1.816555 1.051922 0.712106 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/war.obj 3840x2160');
t1 = [ 2.802288 1.701528 1.050678 0.620784 0.444487 ];
plot(x, t1, 'LineWidth', 3, 'DisplayName', 'models/dragon.obj 3840x2160');
t2 = [ 5.318585 3.083203 1.968052 1.151749 0.804563 ];
plot(x, t2, 'LineWidth', 3, 'DisplayName', 'models/blackdragon.obj 3840x2160');
t3 = [ 5.931814 3.498120 2.295993 1.504625 1.302732 ];
plot(x, t3, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

