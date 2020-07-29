@version = "1.24"
Pod::Spec.new do |s|
  s.name             = 'GhostPlusNative'
  s.version          = @version
  s.summary          = 'Ghost Plus Native Framework'
  s.description      = 'Ghost Plus Native Framework'
  s.homepage         = 'http://www.ghostplus.com'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.authors          = { 'VANSTUDIO' => 'vanstudio@ghost-corps.com' }
  
  s.platform     = :ios, '8.0'
  s.requires_arc = true
  
  s.vendored_frameworks = ['Frameworks/GhostPlusNative.framework']
  
  #s.source           = { :http => 'http://developer.ghostplus.com/project/ghostplus_ios/GhostPlus-1.00.tar.gz', :flatten => true }
  s.source       = { :git => "https://github.com/vanstudio/GhostPlusNative-iOS.git", :tag => @version }
  
  s.source_files = []
  s.resource = 'Frameworks/GhostPlusNative.framework/Versions/A/Resources/GhostPlusNativeResources.bundle'
  
  s.preserve_paths = []
  s.header_dir = 'GhostPlusNative'

  s.frameworks = ['GhostPlusNative']
  #s.libraries = ['stdc++', 'z']
  
  #s.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/TestGhostPlus"' }
  
  s.dependency 'GhostPlus'
end