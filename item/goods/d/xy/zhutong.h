//shen.h ��ң�����������
ITEM_BEGIN(CIzhutong)

virtual void create(int nFlag = 0)		
{
	set_name("��Ͳ", "zhu tong");
	set("long",	"����һ�ڴ������Ͻ���������Ͳ����������װˮ��");
	set("unit", "��");
	set_weight(1000);
	set("value", 1);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting() || me->is_busy())
		return notify_fail("������æ���ء�");
	
	CContainer * env=me->environment();
	if(env->query_temp("thing"))
	{
		if(env->query("index")==1)
		{
			tell_object(me, "\n$HIC��˲�����ˮ������������������ϣ��ͳ���Ͳ����ϲ�ľ�����������һ�������Ͳ��ʢ�˴��Ͳ��ˮ��");
			tell_object(me, "$HIR��õ��ˡ��޸�ˮ����\n");
			load_item("wugenshuei")->move(me);
			destruct(this);
		}
		else if(env->query("index")==2)
		{
			tell_object(me, "\n$HIC��ӯ��ѩ�����Ʈ׹����һ��������ѩ�������������һ���ͳ���Ͳ�����ڿ��С�");
			tell_object(me, "$HIR��õ��ˡ�ѩˮ����\n");
			load_item("xueshuei")->move(me);
			destruct(this);
		}
	}
	else if (env->PresentName("mei shu",IS_ITEM))
	{
		time_t t;	
		struct tm * newtime;
		time(&t);
		newtime = localtime(&t);

		if(newtime->tm_hour < 7 && newtime->tm_hour >6) //ÿ������6����7��ǰ����ȡ��¶ˮ
		{
			tell_object(me, "\n$HIC����ϲ�ķ��������ѿ������ʺ��÷�����峿��¶���ڻ�����Ծ������˸�ž�Ө�Ĺ�ã��");
			tell_object(me, "$HIC���ó���Ͳ��С������Ľ�¶����˽�����");
			tell_object(me, "$HIR��õ��ˡ�¶ˮ����\n");
			load_item("lushuei")->move(me);
			destruct(this);
		}
		else
		{
			tell_object(me, "\n$HIC�㿴����԰������÷��������Ϊ֮������");
		}
	}
	else
		return notify_fail("���ó���Ͳ���˿������ֺ���ûʲô�ô���");
    return 1; 
}

ITEM_END;




