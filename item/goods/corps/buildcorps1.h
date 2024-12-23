// ���Ž�����
// Lanwood 2001-06-4

ITEM_BEGIN(CIbuildcorps1);

void create(int nFlag = 0)
{
    set_name("�����", "yu qing fu");
    set_weight(100);
    
	set("long", "��˵��һ���ɽ����������������,ӵ�д��������ʹ�ɽ��Ž�����ɡ�������");
	set("value", 400);
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	CContainer * env = me->environment();
	if(! env) return 0;

	if(env->query("city")) return notify_fail("���������ܽ����������");
	if(env->query("teshu")) return notify_fail("���������ܽ������񳡾��С�");
	if(env->query("sleep_room")) return notify_fail("���������ܽ������");
	if(env->Query(IS_FIGHTROOM)) return notify_fail("���������ܽ������");
	if(EQUALSTR(env->querystr("area"),"�߲�"))	return notify_fail("���������ܽ������");

	if(me->querymap("corps")) return notify_fail("������˳������������Ż���");
	if(me->query("level") < 120) return notify_fail("�����ڽ����еĵ�λ���������ʸ����ᣡ");
	if(DIFFERSTR(me->querystr("gender"),"Ů��"))	return notify_fail("ֻ��Ů�Բſ��Խ�����������");
	if(me->query("repute") < -100000 ||me->query("repute") > 100000)
		return notify_fail("�����ڽ����е��������������ʸ����ᣡ");
	if(me->query("����") < 100)	return notify_fail("�����ڽ����е��������������ʸ����ᣡ");
		
	AddMenuItem("��Ϊ��ġ�����������֡�", "$2build $1 $2", me);
	SendMenu(me);
	return 1;
}

int build_corps(CChar * me, char * arg)
{
	CContainer * env = me->environment();
	if(! env) return 0;

	if(env->query("city")) return notify_fail("���������ܽ����������");
	if(env->query("sleep_room")) return notify_fail("���������ܽ������");
	
	const char * str = ccheck_legal_name(arg);
	if(str[0]) return notify_fail(str);

	if(me->query("balance") < 50000000l)
		return notify_fail("��������ʺ��������ǧ��");

	char corps_id[20];
	char msg[255];

	sprintf(corps_id, "corp1_%s", me->id(1));
	CRoom * corps = load_room(corps_id);

	if(! corps->query("fail_ob"))		//�Ѿ����˽����
		return notify_fail("����ʧ�ܣ������³��ԣ�");

	if(EQUALSTR(corps->querystr("area"),snprintf(msg, 255,"%s��",arg)))		//�Ѿ����˽����
		return notify_fail("����ʧ�ܣ������³��ԣ���");
		
	me->add("balance", -50000000l);

	corps->del("fail_ob");
	corps->set_name(snprintf(msg, 255,"%s��",arg), corps_id);
	corps->set("door", env->querystr("base_name"));	
	corps->set("area", snprintf(msg, 255,"%s��",arg));
	corps->set("corps_id",corps_id);
	corps->set("level",1);
	corps->set("corp",1);
	corps->set("index",1); //��������
	corps->set("corps/owner_name",me->querystr("name"));//��������
	corps->set("corps/owner_id",me->querystr("id"));//����ID
	corps->set("corps/member_count",1);//���ɳ�Ա��Ŀ
	corps->set("corps/repute",100);//���ɳ�ʼ����
	corps->set("corps/money",2000);//���ɳ�ʼ�Ƹ�
	corps->set(snprintf(msg, 255,"list/%s",me->id(1)),me->name(1));
	
	corps->set("���´��/level",1);
	corps->set("���´��/sh_hp",10000+me->query_temp("max_hp")+me->query("int")*100+me->query("str")*150+me->query("dex")*50+me->query("con")*200);
	corps->set("���´��/sh_mp",100+me->query("max_mp")/100);
	corps->set("���´��/sh_level",1);
	corps->set("���´��/sh_index",random(17));
	corps->set("���´��/sh_combat_exp",1);

	//�����������֮�����������
	int num=random(7)+18;
	int count=84-num;
	corps->set("���´��/sh_str",num);
	num=random(7)+18;
	count=count-num;
	corps->set("���´��/sh_dex",num);
	num=random(7)+18;
	count=count-num;
	corps->set("���´��/sh_con",num);
	corps->set("���´��/sh_int",count);
	corps->set("���´��/sh_per",18+random(15));

	//��ʼ����������Դʱ��
	time_t t;	
	struct tm * newtime;
	time(&t);
	newtime = localtime(&t); 
	corps->set("day",newtime->tm_mday);
	
	corps->remove_all_doors();
	corps->setup();
	corps->Save();
	
	me->set("start_city", corps->querystr("base_name"));
	me->set("corps/id", corps_id);
	me->set("corps/level", 1);
	me->set("corps/rank", "����");
	me->setup();

	me->UpdateMe();
	me->Save();
	me->move(load_room(me->querystr("start_city")));

	message_vision("$HIR���������һ��ҫ�۵Ĺ�â��Ȼ����ʧ�ˡ�\n",me);
	g_Channel.do_channel(this, NULL, "news", 
		snprintf(msg, 255,"$HIW��Ѫ���������̣���Է���������أ��ڵ������$HIR%s(%s)$HIW���տ������ɣ��ӽ��Ժ����ϵ��£�Ψ��$HIC%s��$HIW������"
						,me->name(),me->id(),arg));

	destruct(this);
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "build") == 0)
	{
		return build_corps(me, arg);
	}

	return CItem::handle_action(comm, me, arg);
}

char * ccheck_legal_name(const char * name)
{
   int i;
   CVector v;
   CVector valid_char;
   unsigned char ch[3];
   
   v.append("��");
   v.append("��");
   v.append("��");
   v.append("��");
   v.append("��");
   v.append("�ٰν�");
   v.append("����������");

   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
      
   i = strlen(name);
   
   if( (strlen(name) < 2) || (strlen(name) > 10 ) ) 
   {
		return "�Բ������ֱ����� 1 �� 5 �������֡�";
   }

   while(i--) 
   {
	   ch[0] = (unsigned char)name[i];
	   if( ch[0] <=' ' ) 
	   {
		   return "�Բ������ֲ����ÿ�����Ԫ��";
	   }

	   if( i%2==0 )
	   {
		   if(! ( ch[0] > 160 && ch[0] <255) ) 

	   		   return "�Բ��������á����ġ�ȡ���֡�";

		   ch[1] = (unsigned char)name[i + 1];
		   if(! ( ch[1] > 160 && ch[1] <255)) 
	   		   return "�Բ��������á����ġ���Ӣ�ġ�ȡ���֡�";

		   ch[2] = 0;
		   if(valid_char.find((char *)ch) != valid_char.end() )
			   return "�Բ���������������֡������֡�";			
	   }
   }


   if( v.find(name) != v.end()) 
   {
		return "�Բ����������ֻ���������˵����š�";
   }

   return "";
}

ITEM_END;



