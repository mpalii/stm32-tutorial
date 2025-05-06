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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

void print_number(uint8_t value);

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
  /* USER CODE BEGIN 2 */

  uint8_t result;

  result = 0b01010101;
//  result = 0b10101010;
//  result = 127;
//  result = 254;
//  result = 'h';	// a.k.a. 104

  // Implementation-specific data type, for avr-gcc is a 'long unsigned int'
//  size_t result;

  // 1 byte
//  result = sizeof(char);
//  result = sizeof(unsigned char);
//  result = sizeof(signed char);

  // 4 bytes
//  result = sizeof(int);
//  result = sizeof(unsigned int);
//  result = sizeof(signed int);

  // 4 bytes
//  result = sizeof(long int);
//  result = sizeof(long unsigned int);
//  result = sizeof(long signed int);

  // 8 bytes
//  result = sizeof(long long int);
//  result = sizeof(long long unsigned int);
//  result = sizeof(long long signed int);

  // 2 bytes
//  result = sizeof(short int);
//  result = sizeof(short unsigned int);
//  result = sizeof(short signed int);

  // 4 bytes
//  result = sizeof(float);

  // 8 bytes
//  result = sizeof(double);
//  result = sizeof(long double);

  // 1 byte
//  result = sizeof(void);

  // 4 bytes
//  result = sizeof(char *);
//  result = sizeof(int *);
//  result = sizeof(long *);
//  result = sizeof(long long *);
//  result = sizeof(float *);
//  result = sizeof(double *);
//  result = sizeof(void *);
//  result = sizeof(GPIO_TypeDef*);

  // 1 byte
//  result = sizeof(uint8_t);
//  result = sizeof(int8_t);

  // 2 bytes
//  result = sizeof(uint16_t);
//  result = sizeof(int16_t);

  // 4 bytes
//  result = sizeof(uint32_t);
//  result = sizeof(int32_t);

  // 8 bytes
//  result = sizeof(uint64_t);
//  result = sizeof(int64_t);

//  enum EState{STATE1, STATE2, STATE3};
  // 4 bytes
//  result = sizeof(STATE1);
  // 1 byte
//  result = sizeof(enum EState);

  // 44 bytes
//  result = sizeof(GPIO_TypeDef);

//  result = sizeof(0xFF);                  // 4 bytes
//  result = sizeof(0xffFF);                // 4 bytes
//  result = sizeof(0xFFffFF);              // 4 bytes
//  result = sizeof(0xFFffFFffFFffFF);      // 8 bytes
//  result = sizeof(0xAAbbCCeeDDffAAbbCC);  // 8 bytes (WARNING)

  print_number(result);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, OUT0_Pin|OUT1_Pin|OUT7_Pin|OUT2_Pin
                          |OUT3_Pin|OUT4_Pin|OUT5_Pin|OUT6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : OUT0_Pin OUT1_Pin OUT7_Pin OUT2_Pin
                           OUT3_Pin OUT4_Pin OUT5_Pin OUT6_Pin */
  GPIO_InitStruct.Pin = OUT0_Pin|OUT1_Pin|OUT7_Pin|OUT2_Pin
                          |OUT3_Pin|OUT4_Pin|OUT5_Pin|OUT6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : VCP_RX_Pin */
  GPIO_InitStruct.Pin = VCP_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF1_USART2;
  HAL_GPIO_Init(VCP_RX_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void print_number(uint8_t value)
{
	HAL_GPIO_WritePin(OUT0_GPIO_Port, OUT0_Pin, RESET);
	HAL_GPIO_WritePin(OUT1_GPIO_Port, OUT1_Pin, RESET);
	HAL_GPIO_WritePin(OUT2_GPIO_Port, OUT2_Pin, RESET);
	HAL_GPIO_WritePin(OUT3_GPIO_Port, OUT3_Pin, RESET);
	HAL_GPIO_WritePin(OUT4_GPIO_Port, OUT4_Pin, RESET);
	HAL_GPIO_WritePin(OUT5_GPIO_Port, OUT5_Pin, RESET);
	HAL_GPIO_WritePin(OUT6_GPIO_Port, OUT6_Pin, RESET);
	HAL_GPIO_WritePin(OUT7_GPIO_Port, OUT7_Pin, RESET);

	if (value & (1 << 0)) HAL_GPIO_WritePin(OUT0_GPIO_Port, OUT0_Pin, SET);
	if (value & (1 << 1)) HAL_GPIO_WritePin(OUT1_GPIO_Port, OUT1_Pin, SET);
	if (value & (1 << 2)) HAL_GPIO_WritePin(OUT2_GPIO_Port, OUT2_Pin, SET);
	if (value & (1 << 3)) HAL_GPIO_WritePin(OUT3_GPIO_Port, OUT3_Pin, SET);
	if (value & (1 << 4)) HAL_GPIO_WritePin(OUT4_GPIO_Port, OUT4_Pin, SET);
	if (value & (1 << 5)) HAL_GPIO_WritePin(OUT5_GPIO_Port, OUT5_Pin, SET);
	if (value & (1 << 6)) HAL_GPIO_WritePin(OUT6_GPIO_Port, OUT6_Pin, SET);
	if (value & (1 << 7)) HAL_GPIO_WritePin(OUT7_GPIO_Port, OUT7_Pin, SET);
}

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
