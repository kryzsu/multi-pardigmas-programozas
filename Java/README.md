# JAVA

## code style

* intelliJ integrated plugin
* maven plugin

### intelliJ plugin

* Analyze -> Inspect code

### maven plugin

```xml
<reporting>
        <plugins>
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-site-plugin</artifactId>
                <version>3.7.1</version>
            </plugin>
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-project-info-reports-plugin</artifactId>
                <version>2.9</version>
            </plugin>
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-checkstyle-plugin</artifactId>
                <version>3.0.0</version>
            </plugin>
        </plugins>
    </reporting>
```

generating command line report
```shell
mvn site
```

```shell
open target/site/checkstyle.html
```

## test coverage

* IntelliJ
* maven plugin

### IntelliJ

Run xxx with Coverage

* report in table
* depict in the code editor (green, red, yellow color)

pls use Jacoco runner

Edit Test runner configuration
 - Modify options
   - Specify alternative coverage runner

### maven

```xml
 <build>
        <plugins>
            <plugin>
                <groupId>org.jacoco</groupId>
                <artifactId>jacoco-maven-plugin</artifactId>
                <version>0.8.7</version>
                <executions>
                    <execution>
                        <goals>
                            <goal>prepare-agent</goal>
                        </goals>
                    </execution>
                    <execution>
                        <id>report</id>
                        <phase>prepare-package</phase>
                        <goals>
                            <goal>report</goal>
                        </goals>
                    </execution>
                    <execution>
                        <id>jacoco-check</id>
                        <goals>
                            <goal>check</goal>
                        </goals>
                        <configuration>
                            <rules>
                                <rule>
                                    <element>PACKAGE</element>
                                    <limits>
                                        <limit>
                                            <counter>LINE</counter>
                                            <value>COVEREDRATIO</value>
                                            <minimum>0.8</minimum>
                                        </limit>
                                    </limits>
                                </rule>
                            </rules>
                        </configuration>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>
```

```shell
open target/site/jacoco/index.html
```

ignore any class

```xml
<rule>
 <element>CLASS</element>
<excludes>
  <exclude>com.asimio.demo.Application</exclude>
</excludes>
</rule>
```
coverage ratio

```shell
mvn clean verify
```

break the build if the code coverage is less than COVEREDRATIO

```xml
 <rule>
    <element>PACKAGE</element>
    <limits>
        <limit>
            <counter>LINE</counter>
            <value>COVEREDRATIO</value>
            <minimum>0.8</minimum>
        </limit>
    </limits>
</rule>
```

limit
* counter
* value
* minimum | maximum

counters
* BRANCH
* LINE
* CLASS
* METHOD
* CYCLOMATIC COMPLEXITY

values
* TOTALCOUNT
* COVEREDCOUNT
* MISSEDCOUNT
* COVEREDRATIO
* MISSEDRATIO

## sonarqube

* intelliJ
* maven

### IntelliJ

* Analyze -> Analyze with Sonar Lint

### maven
 section under the <build> tag

```xml
   <pluginManagement>
            <plugins>
                <plugin>
                    <groupId>org.sonarsource.scanner.maven</groupId>
                    <artifactId>sonar-maven-plugin</artifactId>
                    <version>3.7.0.1746</version>
                </plugin>
            </plugins>
</pluginManagement>
```

run the sonarqube in the docker

```shell
docker pull sonarqube
```

```shell
docker run -d --name sonarqube -p 9000:9000 -p 9092:9092 sonarqube
```

https://www.youtube.com/watch?v=b_ah9R7z1HY&t=110s


## profiler
* listening jvm events
* modifies the byte code
  * methodEntered
  * methodExit
  * objectCreated

### IntelliJ

### jstat

usage

```shell
jstat -gc PID 1000
```

output
* S0C	Current survivor space 0 capacity (KB).
* S1C	Current survivor space 1 capacity (KB).
* S0U	Survivor space 0 utilization (KB).
* S1U	Survivor space 1 utilization (KB).
* EC	Current eden space capacity (KB).
* EU	Eden space utilization (KB).
* OC	Current old space capacity (KB).
* OU	Old space utilization (KB).
* PC	Current permanent space capacity (KB).
* PU	Permanent space utilization (KB).
* YGC	Number of young generation GC Events.
* YGCT	Young generation garbage collection time.
* FGC	Number of full GC events.
* FGCT	Full garbage collection time.
* GCT	Total garbage collection time.


### Java VisualVM
jvisualvm

Oracle JDK 6~8

compatible with current jvm also

You should download

### tcpflow

investigate http application 

```shell
apt install tcpflow
```

usage
```shell
sudo tcpflow -i lo port 8080 -c
```
