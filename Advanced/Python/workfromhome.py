import pyautogui
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
import random
import subprocess


def scroll(howmuch, x, y, sleeptime):
    pyautogui.scroll(howmuch, x=x//2, y=x//2)
    time.sleep(sleeptime)

def makeSpiral():
    distance = 100
    while distance > 0:
        pyautogui.drag(distance, 0, duration=0.5)   # move right
        distance -= 5
        pyautogui.drag(0, distance, duration=0.5)   # move down
        pyautogui.drag(-distance, 0, duration=0.5)  # move left
        distance -= 5
        pyautogui.drag(0, -distance, duration=0.5)  # move up

def openSpiralBrowserWindow():
    driver = webdriver.Chrome("/tmp/chromedriver")
    driver.maximize_window()
    driver.get("https://awwapp.com/")
    startbtn = driver.find_element_by_xpath('//*[@id="start-drawing-widget"]/div/div[2]/div[1]/a')
    startbtn.click()
    colorbtn = driver.find_element_by_xpath('//*[@id="aww-toolbar-colors"]/div[1]/img')
    colorbtn.click()
    selectcolor = driver.find_element_by_xpath(random.choice(['//*[@id="aww-toolbar-color-6"]/div/div','//*[@id="aww-toolbar-color-3"]/div/div','//*[@id="aww-toolbar-color-2"]/div/div','//*[@id="aww-toolbar-color-5"]/div/div']))
    selectcolor.click()
    x,y=pyautogui.size()
    pyautogui.moveTo(x//2, y//2)
    time.sleep(3)
    makeSpiral()
    time.sleep(5)
    driver.close()

def runYoutube():
    driver = webdriver.Chrome("/tmp/chromedriver")
    driver.maximize_window()
    driver.get("https://www.youtube.com/watch?v=BosDrdC1IdA")
    time.sleep(3)
    try:
        playbtn = driver.find_element_by_xpath('//*[@id="movie_player"]/div[4]/button')
        playbtn.click()
    except:
        pass
    time.sleep(10)
    githublink = driver.find_element_by_xpath('//*[@id="description"]/yt-formatted-string/a')
    githublink.click()
    time.sleep(5)
    driver.close()

def playDrum(driver):
    for _ in range(7):
        driver.find_elements_by_class_name("l")[0].click()
        time.sleep(0.5)
        driver.find_elements_by_class_name("j")[0].click()
        time.sleep(0.5)
    driver.find_elements_by_class_name("l")[0].click()
    time.sleep(0.5)
    driver.find_elements_by_class_name("k")[0].click()

    return driver


def checkGithub():
    driver = webdriver.Chrome("/tmp/chromedriver")
    driver.maximize_window()
    driver.get("https://github.com/rhythmbhiwani")
    time.sleep(3)
    goToRepo = driver.find_element_by_xpath('//*[@id="js-pjax-container"]/div[1]/div/div/div[2]/div/nav/a[2]')
    goToRepo.click()
    time.sleep(3)
    x,y=pyautogui.size()
    scroll(-5, x=x//2, y=x//2, sleeptime=1)
    scroll(-10, x=x//2, y=x//2, sleeptime=1)
    scroll(-6, x=x//2, y=x//2, sleeptime=1)
    scroll(-5, x=x//2, y=x//2, sleeptime=1)
    scroll(-20, x=x//2, y=x//2, sleeptime=1)
    scroll(50, x=x//2, y=x//2, sleeptime=1)
    repo = driver.find_element_by_xpath('//*[@id="user-repositories-list"]/ul/li[2]/div[1]/div[1]/h3')
    repo.click()
    time.sleep(1)
    scroll(-3, x=x//2, y=x//2, sleeptime=1)
    livewebsite = driver.find_element_by_xpath('//*[@id="readme"]/div[3]/article/p/a')
    livewebsite.click()
    time.sleep(5)
    driver = playDrum(driver)
    time.sleep(5)
    driver.close()

def openTerminal1():
    # pyautogui.hotkey('ctrl', 'alt', 't')
    subprocess.Popen(["gnome-terminal", "-e", "bash"])
    time.sleep(2)
    pyautogui.typewrite('sl && sl \n', interval=1)
    time.sleep(20)
    pyautogui.hotkey('ctrl', 'shift', 'w')

def writeCodeInNano():
    # pyautogui.hotkey('ctrl', 'alt', 't')
    subprocess.Popen(["gnome-terminal", "-e", "bash"])
    time.sleep(5)
    pyautogui.typewrite('nano wfh.txt\n', interval=0.2)
    pyautogui.typewrite('Hello this is the workfromhome command made by RHYTHM BHIWANI\n', interval=0.1)
    pyautogui.typewrite('Check this out at https://github.com/AdHoc-Interns/WorkFromHomen', interval=0.1)
    pyautogui.typewrite('Tools used:\n', interval=0.2)
    pyautogui.typewrite('Python with Selenium\n', interval=0.1)
    pyautogui.typewrite('Bash for setup\n', interval=0.1)
    pyautogui.typewrite('pyautogui for other controls\n', interval=0.1)
    time.sleep(2)
    pyautogui.hotkey('ctrl', 'o')
    time.sleep(1)
    pyautogui.typewrite('\n')
    time.sleep(1)
    pyautogui.hotkey('ctrl', 'x')
    pyautogui.typewrite('cat wfh.txt\n', interval=0.1)
    time.sleep(5)
    pyautogui.hotkey('ctrl', 'shift', 'w')

all_actions = [writeCodeInNano, openTerminal1, checkGithub, runYoutube, openSpiralBrowserWindow]
try:
    t_end = time.time() + 60 * int(input("Enter time in minutes to run : "))
    while time.time() < t_end:
        random.shuffle(all_actions)
        for func in all_actions:
            func()
            time.sleep(2)
except:
    pass
