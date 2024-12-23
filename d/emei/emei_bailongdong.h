ROOM_BEGIN(CREMei_bailongdong);

virtual void create()			
{
	set_name( "峨嵋白龙洞");

	CBox * box = Add_Box();

	box->add_object("coin", 60000);	//put 100 coind into box

	box->set_name( "终焉之印", "enchantment");
	box->Locked("结界", 9000);
	
	add_npc("pub_daoke");    // add by zdn 2001-07-13

	add_door("峨嵋清音阁", "峨嵋清音阁", "峨嵋白龙洞");
	add_door("峨嵋万年庵", "峨嵋万年庵", "峨嵋白龙洞");

	set("long","白龙洞据说是《白蛇传》中的白娘子修炼成仙之处。这里楠木参天，林荫夹道，株株秀挺俊拔，枝叶分披上捧，如两手拥佛，传为古时一高僧按《法华经》口诵一字，植树一株，共植六万九千七百七十七株，时称古德林。这里北上至万年庵，南下是清音阁。(shibei)。由此向西上，左行是黑龙江栈道，右路至白龙洞，东去中峰寺。");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
