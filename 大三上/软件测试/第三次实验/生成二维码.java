package com.example.tests;

import java.util.regex.Pattern;
import java.util.concurrent.TimeUnit;
import org.testng.annotations.*;
import static org.testng.Assert.*;
import org.openqa.selenium.*;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.Select;

public class UntitledTestCase {
  private WebDriver driver;
  private String baseUrl;
  private boolean acceptNextAlert = true;
  private StringBuffer verificationErrors = new StringBuffer();

  @BeforeClass(alwaysRun = true)
  public void setUp() throws Exception {
    driver = new FirefoxDriver();
    baseUrl = "https://www.katalon.com/";
    driver.manage().timeouts().implicitlyWait(30, TimeUnit.SECONDS);
  }

  @Test
  public void testUntitledTestCase() throws Exception {
    driver.get("https://cli.im/text");
    driver.findElement(By.id("text-content")).click();
    driver.findElement(By.id("text-content")).clear();
    driver.findElement(By.id("text-content")).sendKeys("hello world");
    driver.findElement(By.id("click-create")).click();
    driver.findElement(By.linkText("网址")).click();
    driver.findElement(By.id("url_content")).click();
    driver.findElement(By.id("url_content")).clear();
    driver.findElement(By.id("url_content")).sendKeys("https://www.baidu.com");
    driver.findElement(By.id("click-create")).click();
    driver.findElement(By.linkText("文件")).click();
    driver.findElement(By.id("filedatacode")).click();
    driver.findElement(By.id("filedatacode")).clear();
    driver.findElement(By.id("filedatacode")).sendKeys("C:\\fakepath\\03 Wireshark_DNS_v7.0.pdf");
    driver.findElement(By.id("click-create")).click();
    driver.findElement(By.linkText("图片")).click();
    driver.findElement(By.id("filedatacode")).click();
    driver.findElement(By.id("filedatacode")).clear();
    driver.findElement(By.id("filedatacode")).sendKeys("C:\\fakepath\\v2-dcef71380baf9140dd01587f2bb396f7_r.jpg");
    driver.findElement(By.id("click-create")).click();
  }

  @AfterClass(alwaysRun = true)
  public void tearDown() throws Exception {
    driver.quit();
    String verificationErrorString = verificationErrors.toString();
    if (!"".equals(verificationErrorString)) {
      fail(verificationErrorString);
    }
  }

  private boolean isElementPresent(By by) {
    try {
      driver.findElement(by);
      return true;
    } catch (NoSuchElementException e) {
      return false;
    }
  }

  private boolean isAlertPresent() {
    try {
      driver.switchTo().alert();
      return true;
    } catch (NoAlertPresentException e) {
      return false;
    }
  }

  private String closeAlertAndGetItsText() {
    try {
      Alert alert = driver.switchTo().alert();
      String alertText = alert.getText();
      if (acceptNextAlert) {
        alert.accept();
      } else {
        alert.dismiss();
      }
      return alertText;
    } finally {
      acceptNextAlert = true;
    }
  }
}
