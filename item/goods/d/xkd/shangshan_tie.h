//shangshan_tie.h 
//2003-11-3
//侠客岛地图碎片

ITEM_BEGIN(CIshangshan_tie);

virtual void create(int nFlag = 0)		
{
	static struct{
		char id[20];
		char readme[80];
	} miji[9] = {
		{"qing tie1","这是一张破碎的纸片，依稀还可以看到上面有个“赏”字。",},
		{"qing tie2","这是一张破碎的纸片，依稀还可以看到上面有个“善”字。",},
		{"qing tie3","这是一张破碎的纸片，依稀还可以看到上面有个“罚”字。",},
		{"qing tie4","这是一张破碎的纸片，依稀还可以看到上面有个“恶”字。",},
		{"qing tie5","这是一张破碎的纸片，依稀还可以看到上面有个“令”字。",},
		{"qing tie6","这是一张破碎的纸片，依稀还可以看到上面有个“在”字。",},
		{"qing tie7","这是一张破碎的纸片，依稀还可以看到上面有个“襄”字。",},
		{"qing tie8","这是一张破碎的纸片，依稀还可以看到上面有个“阳”字。",},
		{"qing tie9","这是一张破碎的纸片，依稀还可以看到上面有个“城”字。",},
	};

	int lvl = random(9);

	if(nFlag) lvl = nFlag - 1;

	set_name( "破碎的纸片", miji[lvl].id);
	set_weight(1000);	
	set("unit", "片");
	set("long",miji[lvl].readme);
};

virtual int do_look(CChar * me)
{
	char msg[80];
	say(snprintf(msg, 80, "%s",querystr("long")),me);
	say("你拿起纸片看了看，发现上面好像写有东西。",me);
	say("据说如果能够收集到九片不同的碎片，就有可能解开天大的秘密。",me);
	AddMenuItem("仔细看","$0combine $1",me);
	AddMenuItem("算了","",me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "combine") == 0)
		return do_combine(me, arg);
	return 0;
}

int do_combine(CChar *me, char * arg)
{

	CContainer * miji1;
	miji1=me->present("qing tie1");
	
	CContainer * miji2;
	miji2=me->present("qing tie2");
	
	CContainer * miji3;
	miji3=me->present("qing tie3");
	
	CContainer * miji4;
	miji4=me->present("qing tie4");
	
	CContainer * miji5;
	miji5=me->present("qing tie5");
	
	CContainer * miji6;
	miji6=me->present("qing tie6");
	
	CContainer * miji7;
	miji7=me->present("qing tie7");
	
	CContainer * miji8;
	miji8=me->present("qing tie8");
	
	CContainer * miji9;
	miji9=me->present("qing tie9");

	
	if (miji1)
		tell_object(me,"拼上第一张碎片");
	if (miji2)
		tell_object(me,"拼上第二张碎片");
	if (miji3)
		tell_object(me,"拼上第三张碎片");
	if (miji4)
		tell_object(me,"拼上第四张碎片");
	if (miji5)
		tell_object(me,"拼上第五张碎片");
	if (miji6)
		tell_object(me,"拼上第六张碎片");
	if (miji7)
		tell_object(me,"拼上第七张碎片");
	if (miji8)
		tell_object(me,"拼上第八张碎片");
	if (miji9)
		tell_object(me,"拼上第九张碎片");

	if (miji1 && miji2 && miji3 && miji4 && miji5 && miji6 && miji7 && miji8 && miji9)
	{
		destruct(miji1);
		destruct(miji2);
		destruct(miji3);
		
		destruct(miji4);
		destruct(miji5);
		destruct(miji6);
		
		destruct(miji7);
		destruct(miji8);
		destruct(miji9);

		message_vision("$HIC忽然发现这些张碎片似乎可以连在一起，你急忙仔细观看……$COM",me);
		message_vision("$HIC你终于把这些张碎片拼在了一起，然后拿浆糊把他们粘上……$COM",me);

		int i, j, lvl;

		lvl = me->query("level");
		
		if (lvl < 150)
		{
			j=0;
		}
		else
		{
			i = lvl - 149;
			j = random(i);
		}

		if (j>0)
		{
			tell_object(me,"$HIY恭喜你得到了「藏宝图」。$COM");
			load_item("xkd_baotu")->move(me);
		}
		else
		{
			tell_object(me,"$HIY突然一阵清风吹过，你手中拼好的地图在风中化为寸寸碎纸，若蝴蝶般顺风飞去了。。$COM");
		}

		return 1;
	}
	
	tell_object(me,"你把这些碎片左拼右拼，但什么都没拼出来。");
	return 1;
	
}

ITEM_END;








