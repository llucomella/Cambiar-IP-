**CAMBIAR IP**
--------------

Este codigo cambia la ip de la interfaz que digas, solo funciona en maquinas que tengan el idioma en español porque para buscar las interfaces hace un find a "interfaz", si lo quieres usar y tu maquina esta en ingues debes cambiar esta linea:

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   system("netsh interface ipv4 show config | find \"la interfaz\"");   `

Por esta:

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   system("netsh interface ipv4 show config | find \"the interface\"");   `

El resto del codigo es almacena en las variables correspondientes la ip, mascara y gateway.

Finalmente he usado este comando:

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   netsh interface ipv4 set address name="X" static X X X   `

Cambiando las X por las variables en las que se guarda las direcciones que hayas puesto.

He empleado una variable para asi mantener el main limpio y facil de entender.