//shangshan_tie.h 
//2003-11-3
//���͵���ͼ��Ƭ

ITEM_BEGIN(CIshangshan_tie);

virtual void create(int nFlag = 0)		
{
	static struct{
		char id[20];
		char readme[80];
	} miji[9] = {
		{"qing tie1","����һ�������ֽƬ����ϡ�����Կ��������и����͡��֡�",},
		{"qing tie2","����һ�������ֽƬ����ϡ�����Կ��������и����ơ��֡�",},
		{"qing tie3","����һ�������ֽƬ����ϡ�����Կ��������и��������֡�",},
		{"qing tie4","����һ�������ֽƬ����ϡ�����Կ��������и������֡�",},
		{"qing tie5","����һ�������ֽƬ����ϡ�����Կ��������и�����֡�",},
		{"qing tie6","����һ�������ֽƬ����ϡ�����Կ��������и����ڡ��֡�",},
		{"qing tie7","����һ�������ֽƬ����ϡ�����Կ��������и����塱�֡�",},
		{"qing tie8","����һ�������ֽƬ����ϡ�����Կ��������и��������֡�",},
		{"qing tie9","����һ�������ֽƬ����ϡ�����Կ��������и����ǡ��֡�",},
	};

	int lvl = random(9);

	if(nFlag) lvl = nFlag - 1;

	set_name( "�����ֽƬ", miji[lvl].id);
	set_weight(1000);	
	set("unit", "Ƭ");
	set("long",miji[lvl].readme);
};

virtual int do_look(CChar * me)
{
	char msg[80];
	say(snprintf(msg, 80, "%s",querystr("long")),me);
	say("������ֽƬ���˿��������������д�ж�����",me);
	say("��˵����ܹ��ռ�����Ƭ��ͬ����Ƭ�����п��ܽ⿪�������ܡ�",me);
	AddMenuItem("��ϸ��","$0combine $1",me);
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
		tell_object(me,"ƴ�ϵ�һ����Ƭ");
	if (miji2)
		tell_object(me,"ƴ�ϵڶ�����Ƭ");
	if (miji3)
		tell_object(me,"ƴ�ϵ�������Ƭ");
	if (miji4)
		tell_object(me,"ƴ�ϵ�������Ƭ");
	if (miji5)
		tell_object(me,"ƴ�ϵ�������Ƭ");
	if (miji6)
		tell_object(me,"ƴ�ϵ�������Ƭ");
	if (miji7)
		tell_object(me,"ƴ�ϵ�������Ƭ");
	if (miji8)
		tell_object(me,"ƴ�ϵڰ�����Ƭ");
	if (miji9)
		tell_object(me,"ƴ�ϵھ�����Ƭ");

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

		message_vision("$HIC��Ȼ������Щ����Ƭ�ƺ���������һ���㼱æ��ϸ�ۿ�����$COM",me);
		message_vision("$HIC�����ڰ���Щ����Ƭƴ����һ��Ȼ���ý���������ճ�ϡ���$COM",me);

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
			tell_object(me,"$HIY��ϲ��õ��ˡ��ر�ͼ����$COM");
			load_item("xkd_baotu")->move(me);
		}
		else
		{
			tell_object(me,"$HIYͻȻһ����紵����������ƴ�õĵ�ͼ�ڷ��л�Ϊ�����ֽ����������˳���ȥ�ˡ���$COM");
		}

		return 1;
	}
	
	tell_object(me,"�����Щ��Ƭ��ƴ��ƴ����ʲô��ûƴ������");
	return 1;
	
}

ITEM_END;








