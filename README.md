# linux
linux 


### Linux4SAM.org
```
출처 : https://www.microchip.com/en-us/development-tool/Linux4SAM.org

(LINUX SOFTWARE AND TOOLS)
제공 : 
  Device tree support
  Yocto and Buildroot build environments
  AT91 Bootstrap and U-boot bootloaders   <--- **
  OpenWrt support
  Solid and proven peripheral drivers
  Large developer community
  Security updates
  Maintaining multiple stable kernels   <--- ***

 Linux4SAM 웹사이트 제공 내용 : 
    제공하는 리눅스안에 포함되는 컴포넌드 sw를 위한 GitHub repository 
    U-Boot, 
    Yocto Project,
    (모든 MPU를 제공하는 mainline) Buildroot communities 
```

### Yocto
```
  출처 : https://selfish-developer.com/entry/Yocto%EB%9E%80-%EB%AC%B4%EC%97%87%EC%9D%B8%EA%B0%80
  Yocto :  환경세팅시, x86인지 확인해야 하고, 
      어떤 os사용하는지 확인하고,
      os이미지를 램에 올려줄 부트로더는 뭔지 확인하고,
      사용할 컴파일러를 선정하고 다운로드 하고,
      컴파일러가 사용하는 라이브러리를 먼저 설치하고,
      어떤 리눅스 버젼을 사용하는지 확인하고,
             
       등을 형상관리해주는 툴.
      
      (부트로더, 리눅스 커널 소스코드, 시스템이미지를 각각의 git에서 받아오고
      각각의 빌드 스크립트를 작성한후 각각의 폴더에 이미지 파일을 추출해 내는 형태의 환경
      을 만들려고 할때 )
      빌드 결과물과  빌드에 필요한 빌드툴을 yocto 내에서 관리되면, 
      개발자는 특정이미지를 빌드하러 다른 경로로 이동하지 않아도 되고,
      yocto에서 다운받은 컴파일러를 통해서 이미지들이 빌드 되기 때문에 컴파일러를 설치하려고 찾아다닐필요없고,
      yocto 환경 자체를 git에 올려두면, 컴파일 옵션이라던가 필요한 소스코드의 주소를 쉽게 공유할수 있다.
      
      
      사용법 : 
        빌드명령어 : 
          bitbake [target name] 
          
      장점:     
          빌드시  make ARCH=x86_64...이런거 보다는 훨씬 간단
      단점:
         용량을 많이 먹는다. (적어도 50G)
      특징: 
         yocto 다운받으면 빌드에 필요한 코드는 없고, .bb파일들만 가득함.
         .bb 파일 :  소스코드를 받을 위치 (대부분  git )
                    make 옵션과 configure 방법등을 가지고 있는 일종의 스크립트.
         파이썬 많고, 낮선 이름 선언자들 많다.
                   
      동작:
          bootloader,  kernel 의  소스코드를 모두 가져옴,
          (빌드에 필요한) 크로스 컴파일러, 라이브러리도 다운로드해서 받아옴.
             
```      
      
       
       
  
