
NPC_BEGIN(CNwiz_106);

void create()
{
	set_name("��Ͱˮ", "ban tong shuei");
	
	set("title", "����ʹ��");
	set("long","����ǰ�Ͱˮ��ʦ��������רע�ض��Źؿ�ǰ����׼����ʱ����Щ���ҷ��ӷ���������");
	
	set("icon", young_man2);
	set("per",29);
	
	set("gender", "����");
	set("level", 300);
	set("age", 44);

	set("chat_chance", 3);

	set("no_kill",1);
	
}

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "��Ͱˮ��Բ���۾���ȵ�����������Щ���ҷ��ӣ��������������������ȥ����";
	case 1:
        return "��Ͱˮ�ڳ�ǽ�����ص����Ų�����ʱ����������������";
	case 2:
        return "��Ͱˮ���������˵��������̽�����������ƻ�������ı�ƻ������ڸ��ˣ����ƻ��ڶ��³�����̧ͷǰ��ǰ���ƻ�����";
	}
	
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!me->query("chunjie/106/ok") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("����","bai",me);
			AddMenuItem("�����ع�","shou",me);
		}
		else if(!strcmp(ask, "bai") )
		{
			say("��Ͱˮ����һ���֣���ף������ƽ��������˳�⣡��",me);
		}
		else if(!strcmp(ask, "shou") && !query("stop"))
		{
			say("��Ͱˮ���������һ����Ȼ��˵���������ã���һ�����ع�Ҳ��Щ����Ӧ��������ǧ��ҪС�ģ��ƻ����Ӻ��ѶԸ��ġ�",me);
			say("��Ͱˮ������Ц�������������ڿ��ܻ�Ϊʱ���磬��̽���������ƻ�����������ʮ��ǰ��ǰ���Ż���֡���",me);
		}
	}
	SendMenu(me);
	return 1;
}

NPC_END;
