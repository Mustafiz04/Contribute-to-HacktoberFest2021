from locust import HttpLocust, TaskSet, task, between
import json


class Github(TaskSet):
    @task
    def rate_limit(self):
        self.client.get("/rate_limit")

    @task
    def public(self):
        self.client.get("/gists/public")

    @task
    def feeds(self):
        self.client.get("/feeds")

    @task
    def emojis(self):
        self.client.get("/emojis")


class LetsSwarm(HttpLocust):
    host = "https://api.github.com"
    task_set = Github
    wait_time = between(5, 10)