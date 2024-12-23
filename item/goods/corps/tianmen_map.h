ITEM_BEGIN(CItianmen_map);

void create(int nFlag = 0)
{
    set_name("�������ͼ", "tianmen tu");
    set_weight(100);
    
	set("long", "һ�����Ƶ����ͼ,��˵���˴�ͼ�Ϳ��Խ��졸�����š���");
	set("value", 400);
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	if(!me->querymap("corps")) 
		return notify_fail("�������һ��֮������ʹ�á��������ͼ����");
	if(me->query("corps/level")!=1)
		return notify_fail("�������һ��֮������ʹ�á��������ͼ����");

	CContainer * corps = load_room(me->querystr("corps/id"));
	if(corps->query("index")!=1)
		return notify_fail("���������ͼ��ֻ���ɹ�������ʹ�ã�");

	CContainer * env = me->environment();
	if(! env) return 0;
	if(!EQUALSTR(env->querystr("area"),corps->querystr("area")))
		return notify_fail("���������ͼ������Ҫ�����´���з���ʹ�ã�");
	if(!EQUALSTR(env->querystr("name"),"���´��"))
		return notify_fail("���������ͼ������Ҫ�����´���з���ʹ�ã�");
	
	char msg[255];
	if(corps->query("level")>1)
		return notify_fail(snprintf(msg, 255,"��ġ�%s���ƺ��Ѿ�������ˡ������š���",corps->querystr("name")));
	if(corps->query("corps/repute")<250)
		return notify_fail(snprintf(msg, 255,"��ġ�%s���ڽ����е��������������ʸ��졸�����š���",corps->querystr("name")));
	if(corps->query("corps/money")<50000)
		return notify_fail(snprintf(msg, 255,"��ġ�%s��Ŀǰ�Ĳ�������û���㹻������ȥ���졸�����š���",corps->querystr("name")));
	if(corps->query("corps/member_count")<10)
		return notify_fail(snprintf(msg, 255,"��ġ�%s��Ŀǰ����������û���㹻������ȥ���졸�����š���",corps->querystr("name")));

	if(me->query("level") < 122) 
		return notify_fail("�����ڽ����еĵ�λ���������ʸ����ᣡ");
	if(me->query("repute") < -80000 ||me->query("repute") > 80000)
		return notify_fail("�����ڽ����е��������������ʸ����ᣡ");
	if(me->query("����") < 110)	
		return notify_fail("�����ڽ����е��������������ʸ����ᣡ");
	if(me->query("balance") < 10000000l)
		return notify_fail("��������ʺ������һǧ��");

	me->add("balance", -10000000l);

	corps->set("level",2);
	corps->add("corps/money",-20000);
	corps->add("corps/repute",10);
	
	corps->set("������/level",1);
	corps->set("������/sh_hp",10000+me->query_temp("max_hp")+me->query("int")*100+me->query("str")*150+me->query("dex")*50+me->query("con")*200);
	corps->set("������/sh_mp",100+me->query("max_mp")/100);
	corps->set("������/sh_level",1);
	corps->set("������/sh_index",random(17));
	corps->set("������/sh_combat_exp",1);

	//��������̽�����������
	int num=random(7)+18;
	int count=84-num;
	corps->set("������/sh_str",num);
	num=random(7)+18;
	count=count-num;
	corps->set("������/sh_dex",num);
	num=random(7)+18;
	count=count-num;
	corps->set("������/sh_con",num);
	corps->set("������/sh_int",count);
	corps->set("������/sh_per",18+random(15));
	
	//��̬���³���
	char corps_id[40];

	sprintf(corps_id, "g2_������_%s", me->querystr("corps/id"));
	((CRoom *)corps)->remove_doors(snprintf(msg, 255,"g1_���´��_%s",me->querystr("corps/id")));
	((CRoom *)corps)->add_door("������",corps_id, me->querystr("corps/id"));
	
	corps->Save();

	CRoom * corps1= load_room(corps_id);
	
	corps1->set_name("������", corps_id);
	corps1->set("area", corps->querystr("area"));
	corps1->set("corps_id",corps->querystr("corps_id"));
	corps1->set("corps",1);
	corps1->set("level",corps->query("������/level"));
	corps1->del("fail_ob");
	corps1->remove_all_doors();
	corps1->setup();

	corps = load_room(snprintf(msg, 255,"g1_���´��_%s",me->querystr("corps/id")));

	((CRoom *)corps)->remove_doors(me->querystr("corps/id"));
	((CRoom *)corps)->add_door("������",corps_id,  "���´��");
	
	char msg1[512];
	message_vision("$HIR���������ͼ������һ��ҫ�۵Ĺ�â��Ȼ����ʧ�ˡ�",me);
	g_Channel.do_channel(this, NULL, "news", 
		snprintf(msg1, 512,"$HIC��%s��$HIW%s(%s)���������Ľ�$HIC���������ͼ��$HIW�������´���̳֮�ϣ�����ߵ�ݣ�����Ĭ�$HIR\n                        ���³�������������                        ���Ŷ�������������\n                        ��Ө��ת���̲�����                        �����񹬣������̽�!\n$HIWһ������¹������̳�����������������´�˲Ϣ��ض�ɽҡ��һ����¥�ӵص׻���������¥�ϻ�Ȼ�����ֽ���֡�$HIC������$HIW����"
						,env->querystr("area"),me->name(),me->id()));
	
	//�����ڳ�������Ҫ����ˢ��һ�³���,�����޷���ȥ
	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(!userp(target))	continue;
		target->move(env);
	}
	destruct(this);
	return 1;
}

ITEM_END;



