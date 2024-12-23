// ���Ž�����
// Lanwood 2001-06-4

ITEM_BEGIN(CIbuildcorps);

void create(int nFlag = 0)
{
    set_name("����Ȩ״", "builder");
    set_weight(100);
    
	set("long", "���ǹٸ��䷢�Ľ�����ɡ�");        
}

void init()
{
	CContainer * me = environment();

	if(userp(me))
	{
		set("owner", me->id(1));		
	}
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	CContainer * env = me->environment();
	if(! env) return 0;

	if(env->query("city")) return notify_fail("�ܶ治�ܽ����������");
	if(env->query("teshu")) return notify_fail("�ܶ治�ܽ������񳡾��С�");
	if(env->query("sleep_room")) return notify_fail("�ܶ治�ܽ������");
	if(me->querymap("corps")) return notify_fail("������˳������������Ż���");
	if(me->query("level") < 80) return notify_fail("�����ڽ����еĵ�λ���������ʸ����ᣡ");
		
	AddMenuItem("��Ϊ��İ��������֡�", "$2build $1 $2", me);
	SendMenu(me);
	return 1;
}

int build_corps(CChar * me, char * arg)
{
	CContainer * env = me->environment();
	if(! env) return 0;

	if(env->query("city")) return notify_fail("�ܶ治�ܽ����������");
	if(env->query("sleep_room")) return notify_fail("�ܶ治�ܽ������");
	
	const char * str = ccheck_legal_name(arg);
	if(str[0]) return notify_fail(str);

	if(me->query("balance") < 10000000l)
		return notify_fail("��������ʺ������һǧ��");

	char corps_id[20];

	sprintf(corps_id, "corps%05ld", 1 + random(99999));
	CRoom * corps = load_room(corps_id);

	if(! corps->query("fail_ob"))		//�Ѿ����˽����
		return notify_fail("����ʧ�ܣ������³��ԣ�");
		
	me->add("balance", -10000000l);

	corps->del("fail_ob");
	corps->set_name(arg, corps_id);
	corps->set("belong", env->querystr("base_name"));	

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

	tell_object(me, "�ܶ潨����ϡ�");
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
		   if(! ( ch[1] > 160 && ch[1] <255) ) 

	   		   return "�Բ��������á����ġ�ȡ���֡�";

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



