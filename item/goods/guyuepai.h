//xin.h 
//edit by wolfman
//2001-7-24
//ȡ�����ĺ�����

ITEM_BEGIN(CIguyuepai)

virtual void create(int nFlag = 0)		
{
	set_name("������", "guyue pai");
	set_weight(10000);
	
	set("unit", "��");
	set("material", "steel");
	set("long","��˵����ܹ��ռ���ʮ���鲻ͬ�����ƣ����п��ܵõ����ĺ����ơ�");
};

virtual int do_look(CChar * me)
{
	say("���������ƿ��˿����������Ϻ�����ж����������뿴���һ��ʱȴ����ʲô��û�С�",me);
	say("��˵����ܹ��ռ���ʮ���鲻ͬ�����ƣ����п��ܵõ����ĺ����ơ�",me);
	AddMenuItem("��Ū","$0combine $1",me);
	AddMenuItem("����","",me);
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
	char msg[255];
	
	char *bookname[]={"18niou",
		"sword_book1",
		"sword_book2",
		"jiuyin1",
		"hanyuepai",
		"literateb4",
		"lbook3",
		"book_iron",
		"quanpu",
		"miaoshou"};
	int i;
	
	CContainer * yu;
	yu=me->present("yuyue pai");
	
	CContainer * qian;
	qian=me->present("qianyue pai");
	
	CContainer * ming;
	ming=me->present("mingyue pai");
	
	CContainer * leng;
	leng=me->present("lengyue pai");
	
	CContainer * quan;
	quan=me->present("quanyue pai");
	
	CContainer * lian;
	lian=me->present("lianyue pai");
	
	CContainer * qing;
	qing=me->present("qingyue pai");
	
	CContainer * fu;
	fu=me->present("fuyue pai");
	
	CContainer * shui;
	shui=me->present("shuiyue pai");
	
	CContainer * ying;
	ying=me->present("yingyue pai");
	
	CContainer * xie;
	xie=me->present("xieyue pai");
	
	CContainer * an;
	an=me->present("anyue pai");
	
	if (yu && qian && ming && leng && quan && lian && qing && fu && shui && ying && xie && an)
	{
		destruct(yu);
		destruct(qian);
		destruct(ming);
		destruct(leng);
		
		destruct(quan);
		destruct(lian);
		destruct(qing);
		destruct(fu);
		
		destruct(shui);
		destruct(ying);
		destruct(xie);
		destruct(an);
		
		message_vision("$HICͻȻʮ��������ͬʱ����ǿ�ҵĹ�ã���㲻�������ı������۾�����$COM",me);
		message_vision("$HIC����һ���죬$N�о���ʮ��������$N���к϶�Ϊһ����æ�����۾���ȥ����$COM",me);
		i=random(10);
		yu=load_item(bookname[i]);		//��̬װ��Ʒ
		yu->move(me);					//����Ʒ�����

		switch(i)
		{
		case 4:
			tell_object(me,"$HIY��ϲ��õ������ĺ����ơ�$COM");
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "\n\n$HIC%s$HIY����ǧ����࣬���ڻ�������ĺ����ơ�\n\n$COM", me->name(1)));
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s��������ĺ����ơ�", me->name(1)));
			break;
			
		default:
			char msg[255];
			snprintf(msg,255,"$HIYͻȻ$N��ɫ$HIR����$HIW����$HIY������ҡҡ��׹������Ҫ�����ڵأ�ԭ��$N�õ�����%s��$COM",yu->querystr("name"));
			message_vision(msg,me);
		}
		return 1;	
	}
	
	tell_object(me,"��������������Ū�˼��£�ʲô��Ҳû������");
	return 1;
	
/*
	ob->set_name("������", "yuyue pai");
	ob->set_name("ǳ����", "qianyue pai");
	ob->set_name("������", "mingyue pai");
	ob->set_name("������", "lengyue pai");
	
	ob->set_name("Ȫ����", "quanyue pai");
	ob->set_name("������", "lianyue pai");
	ob->set_name("������", "qingyue pai");
	ob->set_name("ˮ����", "shuiyue pai");
	
	ob->set_name("Ӱ����", "yingyue pai");
	ob->set_name("б����", "xieyue pai");
	ob->set_name("������", "anyue pai");
	ob->set_name("������", "fuyue pai");
*/
}

ITEM_END;








