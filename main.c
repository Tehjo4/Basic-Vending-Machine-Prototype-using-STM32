/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fonts.h"
#include "ssd1306.h"
#include "keypad.h"
#include <string.h>
#define BUZZER_PIN GPIO_PIN_7
#define BUZZER_PORT GPIOA

// Keypad rows and columns (example, you may already have these configured)
#define ROW_PORT GPIOB
#define COL_PORT GPIOA
#define SSD1306_COLOR_WHITE 1  // Foreground color
#define SSD1306_COLOR_BLACK 0  // Background color

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
// Define White color for OLED display
//extern const FontDef_t Font_7x10;

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
char key;       // Variable to store key press
uint16_t led_map[10] = {GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15, GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_I2C1_Init(void);
void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  SSD1306_Init();                           // Initialize OLED
  SSD1306_GotoXY(0, 0);                  // Set cursor
  //SSD1306_Puts("Welcome", Font_7x10, White);
  char key_as_string[2] = {key, '\0'};  // Convert 'key' (char) to a string
  SSD1306_Puts(key_as_string, &Font_7x10, SSD1306_COLOR_WHITE);

  SSD1306_UpdateScreen();                   // Display "Welcome" message

  HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET);  // Ensure buzzer is off



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);


	        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) == 0)
	        {
	            SSD1306_GotoXY(30, 30);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
	            SSD1306_Puts("1:MILKSHAKE", &Font_7x10, 1);
	            HAL_Delay(2000);
	            SSD1306_UpdateScreen();
	            HAL_Delay(2000);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
	            HAL_Delay(10);
	            SSD1306_Clear();
	        }
	        else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == 0)
	        {
	            SSD1306_GotoXY(10, 30);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	            SSD1306_Puts("2:CRISPY CORN", &Font_7x10, 1);
	            HAL_Delay(2000);
	            SSD1306_UpdateScreen();
	            HAL_Delay(2000);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	            HAL_Delay(10);
	            SSD1306_Clear();
	        }
	        else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11) == 0)
	        {
	            SSD1306_GotoXY(20, 30);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	            SSD1306_Puts("3:OATS", &Font_16x26, 1);
	            HAL_Delay(2000);
	            SSD1306_UpdateScreen();
	            HAL_Delay(2000);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	            HAL_Delay(10);
	            SSD1306_Clear();
	        }

	        // Scan second row
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);

	        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) == 0)
	        {
	            SSD1306_GotoXY(20, 30);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
	            SSD1306_Puts("4:FIGS", &Font_16x26, 1);
	            HAL_Delay(2000);
	            SSD1306_UpdateScreen();
	            HAL_Delay(2000);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
	            HAL_Delay(10);
	            SSD1306_Clear();
	        }
	        else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == 0)
	        {
	            SSD1306_GotoXY(20, 30);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
	            SSD1306_Puts("5:NUTS", &Font_16x26, 1);
	            HAL_Delay(2000);
	            SSD1306_UpdateScreen();
	            HAL_Delay(2000);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	            HAL_Delay(10);
	            SSD1306_Clear();
	        }
	        else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11) == 0)
	              {
	                  SSD1306_GotoXY(10, 30);
	                  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	                  SSD1306_Puts("6:CHIPS", &Font_16x26, 1);
	                  HAL_Delay(2000);
	                  SSD1306_UpdateScreen();
	                  HAL_Delay(2000);
	                  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	                  HAL_Delay(10);
	                  SSD1306_Clear();
	              }

	        // Scan third row
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);

	        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) == 0)
	        {
	            SSD1306_GotoXY(20, 30);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	            SSD1306_Puts("7:BUN", &Font_16x26, 1);
	            HAL_Delay(2000);
	            SSD1306_UpdateScreen();
	            HAL_Delay(2000);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	            HAL_Delay(10);
	            SSD1306_Clear();
	        }
	        else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == 0)
	        {
	            SSD1306_GotoXY(10, 30);
	            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET);
	            SSD1306_Puts("8:CAKE", &Font_16x26, 1);
	            HAL_Delay(2000);
	            SSD1306_UpdateScreen();
	            HAL_Delay(2000);
	            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
	            HAL_Delay(10);
	            SSD1306_Clear();


	        }
	        else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11) == 0)
	              {
	                  SSD1306_GotoXY(20, 30);
	                  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_SET);
	                  SSD1306_Puts("9:COKE", &Font_16x26, 1);
	                  HAL_Delay(2000);
	                  SSD1306_UpdateScreen();
	                  HAL_Delay(2000);
	                  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET);
	                  HAL_Delay(10);
	                  SSD1306_Clear();}


	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);
	        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) == 0)
	        	        {
	        	            SSD1306_GotoXY(10, 30);
	        	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
	        	            SSD1306_Puts("*:EMPTY", &Font_11x18, 1);
	        	            HAL_Delay(2000);
	        	            SSD1306_UpdateScreen();
	        	            HAL_Delay(2000);
	        	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
	        	            HAL_Delay(10);
	        	            SSD1306_Clear();

	        	        }
	        	        else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == 0)
	        	        {
	        	            SSD1306_GotoXY(20, 30);
	        	            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	        	            SSD1306_Puts("0:MAZA", &Font_16x26, 1);
	        	            HAL_Delay(2000);
	        	            SSD1306_UpdateScreen();
	        	            HAL_Delay(2000);
	        	            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	        	            HAL_Delay(10);

	        	            SSD1306_Clear();
	        	        }
	        	        else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11) == 0)
	        	              {
	        	                  SSD1306_GotoXY(10, 30);

	        	                  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
	        	                  SSD1306_Puts("#:WRONG", &Font_11x18, 1);
	        	                  HAL_Delay(2000);
	        	                  SSD1306_UpdateScreen();
	        	                  HAL_Delay(2000);
	        	                  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
	        	                  HAL_Delay(10);

	        	                  SSD1306_Clear();
	        	                   }

	    }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 1999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 35999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB12 PB13 PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PA9 PA10 PA11 */
  GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
