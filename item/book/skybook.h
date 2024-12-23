//skybook.h

//Sample for ITEM: ��������

ITEM_BEGIN(CIskybook);


virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("��������");	//set item name

 	set_weight(10);		//set item weight

	set("unit", "��");
 	set("long", "���˵����������ڡ��������ı���,��Ϊ������ʶ��,����ʩ�˷�,������������������,�Ǻ�!������äҲ�ܶ���,�쿴��(kan)�ɣ�");
	set("material", "unknow");
 
    set("no_steal", 1);
    set("no_beg", 1);
//    set("no_drop","�ۣ����鶼�붪��,С������Ǵ��");

};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	char team[40];

	if(strcmp(comm, "study") == 0)
		return kan_book(me);
	if(strcmp(comm, "canwu") == 0)
	{
		analyse_string(arg, team, 40);
		return canwu_book(me,atoi(team));
	}
	return 0;
}

int kan_book(CChar *me)
{
	tell_object(me, "���ܣ�ʹ�ò���(canwu)������ͻ���书�ļ��ޣ�������ķ��������ѧ����ſ�������С�ɡ�");
	return 1;
}

int canwu_book(CChar * me,int exp)
{
//	char msg[255];
	say("Ϊ�����ɼ��ƽ�⿼�ǣ���������Ҫ����������������ɺ���ͬʱ���ţ������½⡣",me);
/*	say("�������飬�ȷ϶��顣",me);
	say("���˶��飬δ������",me);
	say("��Ҫ������ȥ���顣",me);
	say("���顢�����ξ�����",me);
*/
	SendMenu(me);
//	int exp1=me->query("combat_exp")-CChar::Level2Exp(me->query("level"))-me->query("sk_exp");
	return 1;
}

/*
int cloud_goto(CChar * me, string id)
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
		if (obj->querystr("id")==id &&  !wizardp(obj))
		{
             tell_object(me,"��һ����������,ֻ����ǰ���Ʒɹ�,���߷�������� ..\n���,��ʹ��,��ˬ,ˬ����!\n������ƻ����½�,��ߴһ��,��!��ȫ��½...");
             me->move(obj->environment());
             return 1;
         }
    }
    
	return 0;
}
*/
virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"ֻ����ǰ���һ��...������.....");

	destruct(this);
}


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp



