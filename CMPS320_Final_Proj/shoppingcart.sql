-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:8889
-- Generation Time: May 28, 2025 at 01:02 AM
-- Server version: 8.0.40
-- PHP Version: 8.3.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `shoppingcart`
--

-- --------------------------------------------------------

--
-- Table structure for table `cart`
--

CREATE TABLE `cart` (
  `id` int NOT NULL,
  `user_id` varchar(20) NOT NULL,
  `product_id` int NOT NULL,
  `price` decimal(5,2) NOT NULL,
  `qty` varchar(2) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `cart`
--

INSERT INTO `cart` (`id`, `user_id`, `product_id`, `price`, `qty`) VALUES
(36, 'jqbWdFKPqkSvvGn65rFI', 1, 100.00, '1');

-- --------------------------------------------------------

--
-- Table structure for table `products`
--

CREATE TABLE `products` (
  `id` int NOT NULL,
  `name` varchar(50) NOT NULL,
  `price` decimal(5,2) NOT NULL,
  `image` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `products`
--

INSERT INTO `products` (`id`, `name`, `price`, `image`) VALUES
(1, 'The Original NASTEE Burger', 100.00, 'assets/images/menu/ognastee.png'),
(2, 'Mystery Meat', 0.99, 'assets/images/menu/mysterymeat.png'),
(3, 'The Dumpster Fire', 12.14, 'assets/images/menu/dumpsterfire.png'),
(4, 'Stove Grease Grilled Cheese', 18.00, 'assets/images/menu/stovegreasegrilledcheese.png'),
(5, 'Sludge Shake', 8.00, 'assets/images/menu/sludgeshake.png'),
(6, 'Crud Sticks', 7.50, 'assets/images/menu/crudsticks.png'),
(7, 'Hairy Fries', 8.00, 'assets/images/menu/hairyfries.png'),
(8, 'Logo Shirt', 24.99, 'assets/images/merch/shirt1.png'),
(9, '\"They Put WHAT in the Stick?\" Shirt', 24.99, 'assets/images/merch/shirt2.png'),
(10, 'Vintage Nastee Burger Shirt', 24.99, 'assets/images/merch/NASTEEMerch1.png'),
(11, 'NEON Nastee Burger Bucket Hat', 20.00, 'assets/images/merch/hat1.png'),
(12, 'Classic Nastee Bucket Hat\r\n', 20.00, 'assets/images/merch/hat2.png');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cart`
--
ALTER TABLE `cart`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `cart`
--
ALTER TABLE `cart`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=37;

--
-- AUTO_INCREMENT for table `products`
--
ALTER TABLE `products`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
