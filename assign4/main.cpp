/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>


/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  // STUDENT TODO 1: return a forecast for the daily weather that is passed in.
  auto min = std::min_element(dailyWeather.begin(), dailyWeather.end());
  auto max = std::max_element(dailyWeather.begin(), dailyWeather.end());
  auto avg = std::accumulate(dailyWeather.begin(), dailyWeather.end(), 0.0) / dailyWeather.size();
  return { *min, *max, avg };
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  /*
   * STUDENT TODO 2: returns a vector of Forecast structs for the weatherData which contains
   * std::vector<double> which contain values for the weather on that day.
   */
  std::vector<Forecast> forecasts;
  std::transform(weatherData.begin(), weatherData.end(), std::back_inserter(forecasts), compute_forecast);
  return forecasts;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 3: return a vector with Forecasts filtered for days with specific weather.
  auto filter = [&](Forecast forecast) {
    return (forecast.max_temp - forecast.min_temp <= kMaxTempRequirement) || (forecast.avg_temp < uAvgTempRequirement);
  };
  std::vector<Forecast> filteredData = forecastData;
  filteredData.erase(std::remove_if(filteredData.begin(), filteredData.end(), filter), filteredData.end());
  return filteredData;
}


std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 4: Make use of a standard library algorithm to shuffle the data!
  std::random_device rd;
  std::mt19937 g(rd());
  std::vector<Forecast> shuffledData = forecastData;
  std::shuffle(shuffledData.begin(), shuffledData.end(), g);
  return shuffledData;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
  // STUDENT TODO 5: Put your functions together to run the weather pipeline!
  std::vector<Forecast>forecastData = get_forecasts(weatherData);
  std::vector<Forecast>filteredData = get_filtered_data(forecastData);
  std::vector<Forecast>shuffledData = get_shuffled_data(filteredData);
  return shuffledData;
}

/* #### Please don't change this line! #### */
#include "utils.cpp"