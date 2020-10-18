#include<bangtal>
#include<ctime>
#include<iostream>

using namespace std;
using namespace bangtal;






int floor(int i) {

	return i / 4;
}

int main() {

	srand((unsigned int)time(NULL));

	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	
	//배경 생성하기
	auto scene1 = Scene::create("강아지단계","my_images/강아지배경.png");
	auto scene2 = Scene::create("강아지단계", "my_images/고양이배경.png");

	//강아지단계==레벨1
	int level = 1;
	

	//강아지랑 대화
	showMessage("와르를ㄹ왕왈왈왕알ㄹㄹ");

	//next 버튼
	//강쥐 대화1
	auto next = Object::create("my_images/play.png",scene1,1200,230);
	//강쥐 대화2
	auto next_1 = Object::create("my_images/play.png", scene1, 1200, 230,false);

	

	//게임 시작 버튼
	auto start= Object::create("my_images/start.png", scene1, 650, 150,false);
	auto start_1 = Object::create("my_images/start.png", scene1, 650, 150, false);

	
	//내가 저지른 폭력죄 레벨 1단계
	int guilty_1 = 0;

	//next 버튼의 횟수 ::강아지
	int next_num = 0;
	next->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		//클릭시 다음대화로 이동

		next_num += 1;

		switch (next_num) {
		
		case 1:
			showMessage("대체 범인이 누구냐 멍!!");
			break;
		case 2:
			showMessage("you!!! 보아하니 내 사연이 궁금한가보구만");
			break;
		case 3:
			showMessage("글쎄 두더지들이 매일 내 밥을 매일 훔쳐먹어!");
			break;
		case 4:
			showMessage("오늘도 모닝똥을 싸고 기분좋게 밥 먹으러 들어오는데,,");
			break;
		case 5:
			showMessage("두더지가 내 밥을 먹고있더라고!");
			break;
		case 6:
			showMessage("두더지답게 지렁이나 먹을 것이지,,");
			break;
		case 7:
			showMessage("뭐? 두더지는 원래 잡식성이라고??");
			break;
		case 8:
			showMessage("잡식이든 비건이든 안물안궁이고!");
			break;
		case 9:
			showMessage("저 두더지들 중 범인이 있다구ㅠㅠ왈왈");
			break;
		case 10:
			showMessage("너무 열받아서 신고하러 경찰서 같다왔는데 인간놈들");
			break;
		case 11:
			showMessage("아주 개말이 개말같지 않지?!");
			break;
		case 12:
			showMessage("아니 글쎄 내 얼굴만 만져대기만 하고 아무 조치도 안 해주더라구");
			break;
		case 13:
			showMessage("안귀여운 강아지주제에 뻥치지 말라고??");
			break;
		case 14:
			showMessage("지는,,, 저리가 혼자있고 싶어 왈,,,");
			break;
		case 15:
			showMessage("미안하다고,,? 맨입으로??? (계획대로 ㅋ)");
			break;
		case 16:
			showMessage("자 그럼 얼른 두더지들 중 내 밥을 강도한 두더지놈을 잡아줘 ㄱㄱ!");
			break;
			
		case 17:  
			next->hide();
			start->show();

		}
		
	

		return true;
	});


	////////대확 파트 ::강얼쥐2
	int next_num_1 = 0;
	next_1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		//클릭시 다음대화로 이동

		next_num_1 += 1;

		switch (next_num_1) {

		case 1:
			if (guilty_1 == 0) {
				showMessage("오! 뭐야 한방에 잡았네? 완전 감 대박이다 너~");
				break;
			}
			else {
				string bla = "아아 무슨 일이야 무고한 " + to_string(guilty_1) + "마리 두더지가 폭행고소장 접수중이래,,";
				showMessage(bla.c_str());
				break;
			}


		case 2:
			showMessage("어쨋든, 저 파렴치한 두더지놈을 잡아줘서 너무 고마워!");
			break;

		case 3:
			showMessage("자 이제 나는 그만 고소장 접수하러가야겠다!");
			break;

		case 4:
			showMessage("복 받을꺼야 친구~!!");
			break;
		case 5:
			showMessage("왈? 게임 끝났어 안가고 뭐하멍~?!");
			break;

		case 6:
			next_1->hide();
			scene2->enter();
		}
	




		return true;
	});



	//두더지 10개 만들기
	//ObjectPtr member1[10];
	int x_length_1 = 50;
	int y_length_1 = 50;

	// 범인의인덱스 
	int index_1 = rand() % 16;

	

	//10칸 간격
	ObjectPtr member1[16];
	int m = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			member1[m] = Object::create("my_images/3_mole4.png", scene1, x_length_1 * j+100, y_length_1 *i+100, false);//5678
			                                                                                                   //1234 꼴
			m++;
		}
		

	}
	
	auto timer = Timer::create(1.0f);
	timer->setOnTimerCallback([&](TimerPtr t)->bool {
		for (int i = 0; i < 16; i++) {
			member1[i]->hide();
		}
		next_1->show();
		return true;
	});

	member1[0]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		
		member1[0]->setImage("my_images/3_mole5.png");
		if (index_1==0) {
			showMessage("ㅋ들킴");
			timer->start();
			
			
		}
		else {
			if (floor(index_1)>floor(0)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(0)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 0) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			
			guilty_1++;

		}
		

		return true;
	});
	member1[1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		member1[1]->setImage("my_images/3_mole5.png");
		if (index_1 == 1) {
			showMessage("ㅋ들킴");
			timer->start();
		}
		else {
			if (floor(index_1) > floor(1)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(1)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 1) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;
		}

		return true;
	});
	member1[2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		member1[2]->setImage("my_images/3_mole5.png");
		if (index_1 == 2) {
			showMessage("ㅋ들킴");
			timer->start();
		}
		else {
			if (floor(index_1) > floor(2)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(2)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 2) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
		
			guilty_1++;
		}
		return true;
	});

	member1[3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		member1[3]->setImage("my_images/3_mole5.png");
		if (index_1 == 3) {
			showMessage("ㅋ들킴");
			timer->start();
		}
		else {
			if (floor(index_1) > floor(3)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(3)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 3) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;
		}
		return true;
	});

	member1[4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		member1[4]->setImage("my_images/3_mole5.png");
		if (index_1 == 4) {
			showMessage("ㅋ들킴");
			timer->start();
		}
		else {
			if (floor(index_1) > floor(4)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(4)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 4) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;

		}
		return true;
	});

	member1[5]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		member1[5]->setImage("my_images/3_mole5.png");
		if (index_1 == 5) {
			showMessage("ㅋ들킴");
			timer->start();
		}
		else {
			if (floor(index_1) > floor(5)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(5)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 5) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;

		}
		return true;
	});
	member1[6]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		member1[6]->setImage("my_images/3_mole5.png");
		if (index_1 == 6) {
			showMessage("ㅋ들킴");
			timer->start();
		}
		else {
			if (floor(index_1) > floor(6)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(6)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 6) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;

		}
		return true;
	});
	member1[7]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		member1[7]->setImage("my_images/3_mole5.png");
		if (index_1 == 7) {
			showMessage("ㅋ들킴");
			timer->start();
		}
		else {
			if (floor(index_1) > floor(7)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(7)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 7) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;

		}
		return true;
	});
	member1[8]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		member1[8]->setImage("my_images/3_mole5.png");
		if (index_1 == 8) {
			showMessage("ㅋ들킴");
			timer->start();
		}
		else {
			if (floor(index_1) > floor(8)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(8)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 8) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;

		}
		return true;
	});
	member1[9]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		member1[9]->setImage("my_images/3_mole5.png");
		if (index_1 == 9) {
			showMessage("ㅋ들킴");
			timer->start();
		}
		else {
			if (floor(index_1) > floor(9)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(9)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 9) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;

		}
		return true;
	});

	member1[10]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {


		member1[10]->setImage("my_images/3_mole5.png");
		if (index_1 == 10) {
			showMessage("ㅋ들킴");
			timer->start();


		}
		else {
			if (floor(index_1) > floor(10)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(10)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 10) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}

			guilty_1++;

		}


		return true;
	});

	member1[11]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {


		member1[11]->setImage("my_images/3_mole5.png");
		if (index_1 == 11) {
			showMessage("ㅋ들킴");
			timer->start();


		}
		else {
			if (floor(index_1) > floor(11)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(11)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 11) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;

		}


		return true;
	});

	member1[12]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {


		member1[12]->setImage("my_images/3_mole5.png");
		if (index_1 == 12) {
			showMessage("ㅋ들킴");
			timer->start();


		}
		else {
			if (floor(index_1) > floor(12)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(12)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 12) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;

		}


		return true;
	});

	member1[13]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {


		member1[13]->setImage("my_images/3_mole5.png");
		if (index_1 == 13) {
			showMessage("ㅋ들킴");
			timer->start();


		}
		else {
			if (floor(index_1) > floor(13)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(13)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 13) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}

			guilty_1++;

		}


		return true;
	});

	member1[14]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {


		member1[14]->setImage("my_images/3_mole5.png");
		if (index_1 == 14) {
			showMessage("ㅋ들킴");
			timer->start();


		}
		else {
			if (floor(index_1) > floor(14)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(14)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 14) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}
			guilty_1++;

		}


		return true;
	});

	member1[15]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {


		member1[15]->setImage("my_images/3_mole5.png");
		if (index_1 == 15) {
			showMessage("ㅋ들킴");
			timer->start();


		}
		else {
			if (floor(index_1) > floor(15)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 위쪽 에 있다구!!");
			}
			else if (floor(index_1) < floor(15)) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 아래쪽 에 있다구!!");
			}
			else if (index_1 > 15) {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 오른쪽에 있다구!!");
			}
			else {
				showMessage("아 왜 때려!! 경찰에 신고할꺼야!! 범인은 내 왼쪽에 있다구!!");
			}

			guilty_1++;

		}


		return true;
	});

	




	
	//스타트 버튼 클릭 시:: 강아지단계
	start->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {


		start->hide();
		//두더지 위치 랜덤 설정
		//크기가 150인 두더지 10개의 칸으로 나눌 수 있음
		//badnorm_coming 두더지 나오는 애니메이션
		if (level == 1) {

			//auto a = Object::create("my_images/1_mole1.png", scene1, 0, 0, false);
			//badnorm_coming(a, 1, 0.01f);
			for (int i = 0; i < 16; i++) {
			
				member1[i]->show();
			}



		}
		
		
		
	
		return true;
	});

	

	
	
	startGame(scene1);


	return 0;
}