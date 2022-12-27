GSSDP with motou hack
=====

zh\_CN:

我在电视上连了一个天猫魔投的盒子，想要用gupnp-av-cp来控制。在gupnp-av-cp能够发现魔投设备，但很快该设备又会在renderer列表中消失。

调试后我发现了原因。天猫魔投连接到无线网后，自身还会成为一个热点（手机可以连接到该热点并上网）。这相当于它在一个无线网卡上有两个地址。例如，对我的盒子，这两个地址分别是192.168.124.104（连接到家庭WiFi的地址）和192.168.49.1（自身热点的地址）。魔投在向外广播自身信息时会发送两遍，Usn相同但Location分别是在这两个地址上。（我不确定这是不是魔投的Bug，因为魔投应该只有一个无线网卡，它应该在这两个地址上广播，并且分别告知相应的Location。SSDP广播地址是239.255.255.250，gupnp-av-cp肯定能收到两遍报文——但是这两遍报文的源IP是相同的，在我的魔投，都是192.168.124.104。或许，最好的方式是魔投给这两个地址分配两个Usn。）这给GSSDP带来了问题。GSSDP在发现设备时，如果收到相同Usn但不同Location的广播消息，会认为是自己错过了byebye消息，并将设备标记为不可用。这就是gupnp-av-cp中设备下线的原因。

为此我创建了这个hack：在收到魔投的广播后，检查其Location的地址是否可达；如果不可达，该消息将被忽略。这可能不是一个好的hack，但恰好对我的魔投可用。

=====

en\_US

I'v got a Motou box connected to my TV for DLNA media casting. I want to control the box with gupnp-av-cp. The Motou box device disappears from the renderer list shortly after it is found by gupnp-av-cp.

I found the reason after some debugging. The box becomes a WiFi AP after it is connected to my home WiFi. Hence it has two IP addresses. For example, my Motou box has an IP address of 192.168.124.104 (connected to my home WiFi) and an IP address of 192.168.49.1 (the gateway address of its AP). When broadcasting its info, the box duplicates the SSDP NOTIFY messages with the same Usn but different Location. This causes some trouble in GSSDP. When a ssdp:alive message is received,  with an Usn seen before but with different Location, GSSDP thinks that it has missed the ssdp:byebye message, and marks the device unavailable.

I created this hack to fix the problem. When receiving a ssdp:alive NOTIFY message, if the address in the Location header is not reachable, the message will be ignored. It just works for my Motou box.

