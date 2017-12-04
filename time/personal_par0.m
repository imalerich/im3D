function sample
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.552460 4.253734 3.908820 4.721333 5.622307 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/war.obj 3840x2160');
t1 = [ 3.439379 2.349961 2.020237 2.277693 2.839429 ];
plot(x, t1, 'LineWidth', 3, 'DisplayName', 'models/dragon.obj 3840x2160');
t2 = [ 5.988099 3.983570 3.708324 4.252135 4.838068 ];
plot(x, t2, 'LineWidth', 3, 'DisplayName', 'models/blackdragon.obj 3840x2160');
t3 = [ 5.961468 3.550811 2.639570 2.942769 3.220608 ];
plot(x, t3, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

